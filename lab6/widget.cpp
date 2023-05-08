#include "widget.h"

Widget::Widget(QWidget* parent)
    : QWidget(parent)
{
    resize(500, 500);
    spinBox = new QSpinBox(this);
    timer = new QTimer(this);

    triangle = new Triangle(QPoint(width()/2 - size/2, height()/2 - size/2), size);

    connect(timer, &QTimer::timeout, this, &Widget::timerTimeOut);
    connect(spinBox, &QSpinBox::valueChanged, this, &Widget::spinBoxValueChanged);
    brush = QBrush(QColor(rand() % 255, rand() % 255, rand() % 255, 255));

    spinBox->setRange(1, 2000);
    spinBox->setValue(1000);
    timer->start(1000);
}

Widget::~Widget()
{}

void Widget::paintEvent(QPaintEvent* e)
{
    QPainter painter(this);

    painter.setBrush(brush);

    QPolygon trianglePolygon(triangle->GetPoints());

    painter.drawPolygon(trianglePolygon);
}

void Widget::spinBoxValueChanged(int value)
{
    timer->setInterval(value);
}

void Widget::timerTimeOut()
{
    if (triangleDirection == Direction::Left && triangle->leftBottom.x() - triangleSpeed <= 0)
    {
         triangleDirection = Direction::Bottom;
         brush.setColor(QColor(rand() % 255, rand() % 255, rand() % 255, 255));
    }

    if (triangleDirection == Direction::Bottom && triangle->rightBottom.y() + triangleSpeed >= height())
    {
        triangleDirection = Direction::Right;
        brush.setColor(QColor(rand() % 255, rand() % 255, rand() % 255, 255));
    }

    if (triangleDirection == Direction::Right && triangle->rightBottom.x() + triangleSpeed >= width())
    {
        triangleDirection = Direction::Top;
        brush.setColor(QColor(rand() % 255, rand() % 255, rand() % 255, 255));
    }

    if (triangleDirection == Direction::Top && triangle->middleTop.y() - triangleSpeed <= 0)
    {
        triangleDirection = Direction::Left;
        brush.setColor(QColor(rand() % 255, rand() % 255, rand() % 255, 255));
    }

    triangle->move(triangleDirection, triangleSpeed);
    update();
}
