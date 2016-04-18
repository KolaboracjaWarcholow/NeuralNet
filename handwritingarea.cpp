#include "handwritingarea.h"
#include <QScrollArea>

HandWritingArea::HandWritingArea()
{
   setSceneRect(0,0,160,160);
}
void HandWritingArea::mousePressEvent(QGraphicsSceneMouseEvent *event){
    mouseButton = pressed;
    cursorX= event->scenePos().x();
    cursorY= event->scenePos().y();
    QPen pen;
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    addRect(QRectF(cursorX, cursorY, 10, 10),pen , brush);
    QGraphicsScene::mouseMoveEvent(event);
}
void HandWritingArea::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if(mouseButton==pressed)
    {
        cursorX= event->scenePos().x();
        cursorY= event->scenePos().y();
        QPen pen;
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        addRect(QRectF(cursorX, cursorY, 10, 10),pen , brush);
        QGraphicsScene::mouseMoveEvent(event);
    }
}
void HandWritingArea::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    mouseButton = released;
}
