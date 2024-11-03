#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <iostream>
#include <QDebug>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btn_save_clicked();
    void on_btn_close_clicked();
    void on_btn_edit_clicked();
    void mySlot();

    void on_btn_open_clicked();

signals:
    void mySignal();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
