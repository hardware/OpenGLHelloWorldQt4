#include "window.h"

Window::Window(const QGLFormat &context, QWidget *parent) : QGLWidget(context, parent), m_vertexBuffer(QGLBuffer::VertexBuffer)
{
    startTimer(30);
}

void Window::timerEvent(QTimerEvent*)
{
    updateGL();
}

void Window::initializeGL()
{
    glewExperimental = GL_TRUE;

    GLenum error = glewInit();

    if(error != GLEW_OK)
        qCritical() << "GLEW init error : " << glewGetErrorString(error);

    QGLFormat glFormat = QGLWidget::format();

    if( ! glFormat.sampleBuffers())
        qWarning() << "Could not enable sample buffers";

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    prepareShaderProgram();
    prepareVertexBuffer();
}

void Window::resizeGL(int w, int h)
{
    glViewport(0, 0, w, qMax(h, 1));
}

void Window::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Window::prepareVertexBuffer()
{
    float points[] = {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };

    m_vertexBuffer.create();
    m_vertexBuffer.setUsagePattern(QGLBuffer::StaticDraw);
    m_vertexBuffer.bind();
    m_vertexBuffer.allocate(points, 3 * 2 * sizeof(float));

    m_shader.bind();
    m_shader.setAttributeBuffer("vertex", GL_FLOAT, 0, 2);
    m_shader.enableAttributeArray("vertex");
}

void Window::prepareShaderProgram()
{
    if ( ! m_shader.addShaderFromSourceFile(QGLShader::Vertex, ":/resources/shaders/simple.vert") )
        qWarning() << m_shader.log();

    if ( ! m_shader.addShaderFromSourceFile(QGLShader::Fragment, ":/resources/shaders/simple.frag") )
        qWarning() << m_shader.log();

    if ( ! m_shader.link() )
        qWarning() << m_shader.log();
}
