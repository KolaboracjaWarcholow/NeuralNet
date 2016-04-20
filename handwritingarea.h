#ifndef HANDWRITINGAREA_H
#define HANDWRITINGAREA_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QPointF>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QPen>

class HandWritingArea :public QGraphicsScene
{
public:
    enum mouseClick {released,pressed};
    HandWritingArea();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    mouseClick mouseButton;
    float cursorX = 0;
    float cursorY = 0;


};

#endif // HANDWRITINGAREA_H
