#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    initializeGLContext();
    initializeGLArea();
    initializeParamsArea();

    resize(600, 400);
}

void MainWindow::initializeGLContext()
{
    glContext.setProfile(QGLFormat::CoreProfile);
    glContext.setDoubleBuffer(true);
    glContext.setDepthBufferSize(24);
    glContext.setVersion(3, 3);
    glContext.setSampleBuffers(true);
}

void MainWindow::initializeGLArea()
{
    glAera = new Window(glContext, this);
    setCentralWidget(glAera);
}

void MainWindow::initializeParamsArea()
{
    dockArea = new QDockWidget("Parameters", this);
    addDockWidget(Qt::RightDockWidgetArea, dockArea);
}
