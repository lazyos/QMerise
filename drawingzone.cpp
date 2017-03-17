#include "drawingzone.h"

DrawingZone::DrawingZone(QWidget *parent) : QOpenGLWidget(parent)
{

}

void DrawingZone::initializeGL()
{
    // Set up the rendering context, load shaders and other resources, etc.:
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void DrawingZone::paintGL()
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glClear(GL_COLOR_BUFFER_BIT);
}


void DrawingZone::paintEvent(QPaintEvent *e)
{
    // init objects to paint
    QPainter painter(this);
    QPen pen = QPen();
    QRect rect(x, y, 90, 180);

    // Set painting attributes
    pen.setColor(QColor().black());
    pen.setWidth(5);
    painter.setPen(pen);

    // Paint the rect
    painter.drawRect(rect);
}

void DrawingZone::mousePressEvent(QMouseEvent *e)
{
    this->x = e->x();
    this->y = e->y();

    repaint();
}
