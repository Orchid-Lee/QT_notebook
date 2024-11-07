#include "mybutton.h"



MyButton::MyButton(QWidget *parent)
    : QWidget{parent}
{
    pix.load(":/icon/setting.svg");
    setFixedSize(pix.size());
    update();
}

void MyButton::mousePressEvent(QMouseEvent *event)
{
    pix.load(":/icon/setting_press.svg");
    qDebug() << "self mouse press.";
    update();
    emit clicked();
}

void MyButton::leaveEvent(QEvent *event)
{
    pix.load(":/icon/setting.svg");
    update();
}

void MyButton::enterEvent(QEnterEvent *event)
{
    qDebug() << "self button enter.";
}

void MyButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), pix);
}

