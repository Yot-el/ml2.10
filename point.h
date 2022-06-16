#ifndef POINT_H
#define POINT_H

class QPoint;
class QPainter;
class Point
{
public:
    Point();
    Point(int x, int y, int size=3, int width = 1);
    int getX() const;
    void setX(int newX);

    int getY() const;
    void setY(int newY);

    int getSize() const;
    void setSize(int newSize);

    virtual void draw(QPainter *painter);
    int distance2(const QPoint &point);

    int getWidth() const;
    void setWidth(int newWidth);

private:
    int x, y, size, width;

};

#endif // POINT_H
