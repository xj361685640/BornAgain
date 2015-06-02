#include "Rectangle.h"
#include <iostream>
#include <cmath>

Rectangle::Rectangle(qreal posX, qreal posY, qreal width, qreal heigth)
    : m_posX(posX)
    , m_posY(posY)
    , m_width(width)
    , m_heigth(heigth)
    , m_topLeftCorner(new QGraphicsRectItem(m_posX-5, m_posY-5, 10, 10))
    , m_bottomLeftCorner(new QGraphicsRectItem(m_posX + m_width -5, m_posY-5, 10, 10))
    , m_topRightCorner(new QGraphicsRectItem(m_posX + m_width -5, m_posY-5, 10, 10))
    , m_bottomRightCorner(new QGraphicsRectItem(m_posX + m_width -5, m_posY + m_heigth -5, 10, 10))
    , m_resizeMode(false)
    , m_rotationMode(false)
{
    this->setFlag(QGraphicsItem::ItemIsSelectable);
    this->cursor().setShape(Qt::ClosedHandCursor);
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    delete m_topLeftCorner;
    delete m_topRightCorner;
    delete m_bottomLeftCorner;
    delete m_bottomRightCorner;

    painter->setRenderHints( QPainter::Antialiasing);
    this->prepareGeometryChange();
    painter->drawRect(m_posX, m_posY, m_width, m_heigth);

    if(this->isSelected()) {
        painter->setBrush(Qt::green);
        this->prepareGeometryChange();
        painter->drawRect(m_posX-5, m_posY-5, 10, 10);
        this->prepareGeometryChange();
        painter->drawRect(m_posX + m_width -5, m_posY-5, 10, 10);
        this->prepareGeometryChange();
        painter->drawRect(m_posX-5, m_posY + m_heigth -5, 10, 10);
        this->prepareGeometryChange();
        painter->drawRect(m_posX + m_width -5, m_posY + m_heigth -5, 10, 10);
    }
    m_topLeftCorner = new QGraphicsRectItem(m_posX-5, m_posY-5, 10, 10);
    m_bottomLeftCorner = new QGraphicsRectItem(m_posX-5, m_posY + m_heigth -5, 10, 10);
    m_topRightCorner = new QGraphicsRectItem(m_posX + m_width -5, m_posY-5, 10, 10);
    m_bottomRightCorner = new QGraphicsRectItem(m_posX + m_width -5, m_posY + m_heigth -5, 10, 10);

}

QRectF Rectangle::boundingRect() const
{
    return QRectF(m_posX-10, m_posY-10  , m_width+50, m_heigth+50);
}

void Rectangle::checkResizeRules(QGraphicsSceneMouseEvent *event)
{
    if(m_corner == TOPLEFT) {
        if(m_topLeftCorner->pos().x() <= event->pos().x()) {
            m_corner = TOPRIGHT;
            setCursor(Qt::SizeBDiagCursor);
        }
        else if(m_bottomLeftCorner->pos().y() <= event->pos().y()) {
            m_corner = BOTTOMLEFT;
            setCursor(Qt::SizeBDiagCursor);
        }
    }
    else if(m_corner == TOPRIGHT) {
        if(event->pos().x() <= m_topLeftCorner->pos().x()) {
            m_corner = TOPLEFT;
            setCursor(Qt::SizeFDiagCursor);
        }
        else if(m_bottomRightCorner->pos().y() <= event->pos().y()) {
            m_corner = BOTTOMRIGHT;
            setCursor(Qt::SizeFDiagCursor);
        }
    }
    else if(m_corner == BOTTOMLEFT) {
        if(m_bottomRightCorner->pos().x() <= event->pos().x()) {
            m_corner = BOTTOMRIGHT;
            setCursor(Qt::SizeFDiagCursor);
        }
        else if(event->pos().y() <= m_bottomRightCorner->pos().y()) {
            m_corner = TOPLEFT;
            setCursor(Qt::SizeFDiagCursor);
        }
    }
    else if(m_corner == BOTTOMRIGHT) {
        if(event->pos().x() <= m_bottomRightCorner->pos().x()) {
            m_corner = BOTTOMLEFT;
            setCursor(Qt::SizeBDiagCursor);
        }
        else if(event->pos().y() <= m_bottomRightCorner->pos().y()) {
            m_corner = TOPRIGHT;
            setCursor(Qt::SizeBDiagCursor);
        }
    }
}

void Rectangle::calculateResize(QGraphicsSceneMouseEvent *event)
{
    if(m_corner == TOPLEFT) {
        this->setFlag(QGraphicsItem::ItemIsMovable, false);
        checkResizeRules(event);
        m_width = m_topRightCorner->pos().x() - event->pos().x();
        m_heigth = m_bottomLeftCorner->pos().y() - event->pos().y();
        m_posX = event->pos().x();
        m_posY = event->pos().y();


    }
    else if(m_corner == BOTTOMLEFT) {
        this->setFlag(QGraphicsItem::ItemIsMovable, false);
        checkResizeRules(event);
        m_width = m_bottomRightCorner->pos().x() - event->pos().x();
        m_heigth = event->pos().y() - m_topLeftCorner->pos().y();
        m_posX = event->pos().x();
        m_posY = event->pos().y() - m_heigth;
    }
    else if(m_corner == TOPRIGHT) {
        this->setFlag(QGraphicsItem::ItemIsMovable, false);
        checkResizeRules(event);
        m_width = event->pos().x() - m_topLeftCorner->pos().x() ;
        m_heigth = m_bottomRightCorner->pos().y() - event->pos().y();
        m_posX = event->pos().x() - m_width;
        m_posY = event->pos().y();
    }

    else if(m_corner == BOTTOMRIGHT) {
        this->setFlag(QGraphicsItem::ItemIsMovable, false);
        checkResizeRules(event);
        m_width =  event->pos().x() - m_bottomLeftCorner->pos().x();
        m_heigth = event->pos().y() - m_topRightCorner->pos().y();
        m_posX = event->pos().x() - m_width;
        m_posY = event->pos().y() - m_heigth;
    }
}

qreal Rectangle::calculateRotation(QGraphicsSceneMouseEvent *event)
{
    qreal lengthOfHypotenuse = sqrt(pow(m_width/2, 2) + pow(m_heigth/2,2));
    std::cout << lengthOfHypotenuse << " " << m_width << " " << m_heigth << std::endl;
    qreal offsetAngle = acos((m_width/2)/lengthOfHypotenuse)*180/M_PI;

    if(m_corner == TOPLEFT) {
        qreal radians =  atan((event->scenePos().y() - this->mapToScene(m_posX+m_width/2, m_posY+m_heigth/2).y())/(event->scenePos().x() - this->mapToScene(m_posX+m_width/2, m_posY+m_heigth/2).x()));
        std::cout << radians *180/M_PI<< " " <<  offsetAngle*180/M_PI << " " << "TOPLEFT" << std::endl;
        return radians*180/M_PI - offsetAngle;
    }
    else if(m_corner == TOPRIGHT) {
        qreal radians =  atan((event->scenePos().y()- this->mapToScene(m_posX+m_width/2, m_posY+m_heigth/2).y())/(event->scenePos().x() - this->mapToScene(m_posX+m_width/2,  m_posY+m_heigth/2).x()));
        std::cout << radians*180/M_PI << " " << "TOPRIGHT" << std::endl;
        return radians*180/M_PI - offsetAngle;
    }
    else if(m_corner == BOTTOMLEFT) {
       qreal radians =  atan((event->scenePos().y()- this->mapToScene(m_posX+m_width/2, m_posY+m_heigth/2).y())/(event->scenePos().x()- this->mapToScene(m_posX+m_width/2, m_posY+m_heigth/2).x()));
        std::cout << radians*180/M_PI << " " << "BOTTOMLEFT" << std::endl;
        return radians*180/M_PI - offsetAngle;
    }
    else if(m_corner == BOTTOMRIGHT) {
        qreal radians =  atan((event->scenePos().y()- this->mapToScene(m_posX+m_width/2,  m_posY+m_heigth/2).y())/(event->scenePos().x()- this->mapToScene(m_posX+m_width/2,  m_posY+m_heigth/2).x()));
        std::cout << radians*180/M_PI << " " << "BOTTOMRIGHT" << std::endl;
        return radians*180/M_PI - offsetAngle;
    }
    return 0;
}

void Rectangle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{


    if(event->button() == Qt::LeftButton && m_topLeftCorner->contains(event->pos())) {
        m_resizeMode = true;
        m_corner = TOPLEFT;
        this->setFlag(QGraphicsItem::ItemIsMovable, false);
        setCursor(Qt::SizeFDiagCursor);

    }
    else if(event->button() == Qt::LeftButton &&  m_bottomLeftCorner->contains(event->pos())) {
        m_resizeMode = true;
         m_corner = BOTTOMLEFT;
        this->setFlag(QGraphicsItem::ItemIsMovable, false);
        setCursor(Qt::SizeBDiagCursor);
    }
    else if(event->button() == Qt::LeftButton &&  m_topRightCorner->contains(event->pos())) {
        m_resizeMode = true;
        m_corner = TOPRIGHT;
        this->setFlag(QGraphicsItem::ItemIsMovable, false);
        setCursor(Qt::SizeBDiagCursor);
    }

    else if(event->button() == Qt::LeftButton &&  m_bottomRightCorner->contains(event->pos())) {
        m_resizeMode = true;
        m_corner = BOTTOMRIGHT;
        this->setFlag(QGraphicsItem::ItemIsMovable, false);
        setCursor(Qt::SizeFDiagCursor);
    }
    else {

        this->setFlag(QGraphicsItem::ItemIsMovable, true);
        QGraphicsItem::mousePressEvent(event);
    }
    this->setFlag(QGraphicsItem::ItemIsMovable, true);

}

void Rectangle::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_corner != NONE && m_resizeMode) {
        calculateResize(event);
    }
    else if(m_corner != NONE && m_rotationMode) {
        QTransform transform;
        transform.translate(m_posX + m_width*0.5, m_posY + m_heigth*0.5);
        transform.rotate(calculateRotation(event));
        transform.translate(-( m_posX + m_width*0.5), -( m_posY + m_heigth*0.5));
        setTransform(transform);
    }
    else {
        this->setFlag(QGraphicsItem::ItemIsMovable, true);
        QGraphicsItem::mouseMoveEvent(event);
    }
    this->setFlag(QGraphicsItem::ItemIsMovable, true);

}

void Rectangle::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setFlag(QGraphicsItem::ItemIsMovable, true);
    m_resizeMode = false;
    m_rotationMode = false;
    setCursor(Qt::ArrowCursor);
    QGraphicsItem::mouseReleaseEvent(event);

}

void Rectangle::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && m_topLeftCorner->contains(event->pos())) {
        m_resizeMode = false;
        m_rotationMode = true;
        m_corner = TOPLEFT;
        this->setFlag(QGraphicsItem::ItemIsMovable, false);
        setCursor(Qt::ClosedHandCursor);

    }
    else if(event->button() == Qt::LeftButton &&  m_bottomLeftCorner->contains(event->pos())) {
        m_resizeMode = false;
        m_rotationMode = true;
         m_corner = BOTTOMLEFT;
        this->setFlag(QGraphicsItem::ItemIsMovable, false);
        setCursor(Qt::ClosedHandCursor);
    }
    else if(event->button() == Qt::LeftButton &&  m_topRightCorner->contains(event->pos())) {
        m_resizeMode = false;
        m_rotationMode = true;
        m_corner = TOPRIGHT;
        this->setFlag(QGraphicsItem::ItemIsMovable, false);
        setCursor(Qt::ClosedHandCursor);
    }

    else if(event->button() == Qt::LeftButton &&  m_bottomRightCorner->contains(event->pos())) {
        m_resizeMode = false;
        m_rotationMode = true;
        m_corner = BOTTOMRIGHT;
        this->setFlag(QGraphicsItem::ItemIsMovable, false);
        setCursor(Qt::ClosedHandCursor);
    }
    else {
        m_resizeMode = false;
        m_rotationMode = false;
        this->setFlag(QGraphicsItem::ItemIsMovable, true);
        QGraphicsItem::mouseDoubleClickEvent(event);
    }
    this->setFlag(QGraphicsItem::ItemIsMovable, true);
}
