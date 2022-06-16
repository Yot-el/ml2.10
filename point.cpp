#include "point.h"
#include <QPainter>

Point::Point()
    :Point(0,0,0,0)
{
}

Point::Point(int x, int y, int size, int width)
    :x(x),y(y),size(size),width(width)
{
}

int Point::getX() const
{
    return x;
}

void Point::setX(int newX)
{
    x = newX;
}

int Point::getY() const
{
    return y;
}

void Point::setY(int newY)
{
    y = newY;
}

int Point::getSize() const
{
    return size;
}

void Point::setSize(int newSize)
{
    size = newSize;
}

void Point::draw(QPainter *painter)
{
    QPen pen;
    pen.setWidth(width);
    painter->setPen(pen);
    painter->drawLine(x-size, y, x+size, y);
    painter->drawLine(x, y-size, x, y+size);
}

int Point::distance2(const QPoint &point)
{
    int distance = (this->x)^2 + point.x()^2 + (this->y)^2 + point.y()^2;
    return distance;
}

int Point::getWidth() const
{
    return width;
}

void Point::setWidth(int newWidth)
{
    width = newWidth;
}
