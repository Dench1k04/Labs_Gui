#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>

enum Direction
{
    Top,
    Right,
    Bottom,
    Left
};

class Triangle
{
public:
    QPoint middleTop;
    QPoint rightBottom;
    QPoint leftBottom;

    Triangle(QPoint point, int size)
    {
        SetPosition(point,size);
    }

    void SetPosition(QPoint point, int size)
    {
        int x = point.x();
        int y = point.y();

        middleTop = QPoint(x, y-size*2);
        rightBottom = QPoint(x+size, y);
        leftBottom = QPoint(x-size, y);
    }

    QList<QPoint> GetPoints()
    {
        QList<QPoint> points;

        points.append(middleTop);
        points.append(rightBottom);
        points.append(leftBottom);

        return points;
    }

    void move(Direction direction, int amount)
    {
        switch (direction)
        {
        case Direction::Top:
            middleTop.setY(middleTop.y() - amount);
            rightBottom.setY(rightBottom.y() - amount);
            leftBottom.setY(leftBottom.y() - amount);
            break;

        case Direction::Right:
            middleTop.setX(middleTop.x() + amount);
            rightBottom.setX(rightBottom.x() + amount);
            leftBottom.setX(leftBottom.x() + amount);
            break;

        case Direction::Bottom:
            middleTop.setY(middleTop.y() + amount);
            rightBottom.setY(rightBottom.y() + amount);
            leftBottom.setY(leftBottom.y() + amount);
            break;

        case Direction::Left:
            middleTop.setX(middleTop.x() - amount);
            rightBottom.setX(rightBottom.x() - amount);
            leftBottom.setX(leftBottom.x() - amount);
            break;
        }
    }
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget* parent = nullptr);
    ~Widget();

private:
    QSpinBox* spinBox;
    QTimer* timer;

    Triangle* triangle;
    Direction triangleDirection = Direction::Left;
    int triangleSpeed = 10;
    int size = 50;
    QBrush brush;

    void paintEvent(QPaintEvent* e);

public slots:
    void timerTimeOut();
    void spinBoxValueChanged(int);

};

#endif // WIDGET_H
