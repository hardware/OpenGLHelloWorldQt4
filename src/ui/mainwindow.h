#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "window.h"

#include <QMainWindow>
#include <QtGui>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);

    void initializeGLContext();
    void initializeGLArea();
    void initializeParamsArea();

private:

    Window      *glAera;
    QWidget     *paramsArea;
    QDockWidget *dockArea;
    QGLFormat   glContext;

};

#endif // MAINWINDOW_H
