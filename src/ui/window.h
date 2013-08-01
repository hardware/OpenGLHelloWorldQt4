#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>

#include <QGLWidget>
#include <QGLBuffer>
#include <QGLShaderProgram>
#include <QMessageBox>
#include <QDebug>

class Window : public QGLWidget
{

    Q_OBJECT

public:

    explicit Window(const QGLFormat &context, QWidget *parent = 0);

    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();

private:
    virtual void timerEvent(QTimerEvent*);

    void prepareVertexBuffer();
    void prepareShaderProgram();

    QGLBuffer        m_vertexBuffer;
    QGLShaderProgram m_shader;

};

#endif // WINDOW_H
