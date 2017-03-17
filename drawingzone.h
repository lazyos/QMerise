#ifndef DRAWINGZONE_H
#define DRAWINGZONE_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QPen>
#include <QColor>

class DrawingZone : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit DrawingZone(QWidget *parent = 0);

signals:

public slots:

protected:
    void initializeGL();
    void paintGL();
    virtual void paintEvent(QPaintEvent *e);
    virtual void mousePressEvent(QMouseEvent *event);

private:
    int x;
    int y;
};

#endif // DRAWINGZONE_H
