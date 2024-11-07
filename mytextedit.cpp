#include "mytextedit.h"



MyTextEdit::MyTextEdit(QWidget *parent) : QTextEdit(parent)
{

}

void MyTextEdit::wheelEvent(QWheelEvent *event)
{
    qDebug() << "wheel:" << event->angleDelta();
}

void MyTextEdit::keyPressEvent(QKeyEvent *event)
{

}

void MyTextEdit::keyReleaseEvent(QKeyEvent *event)
{

}
