#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <iostream>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QElapsedTimer>
#include <QTextDocument>
#include <QMessageBox>
#include <time.h>
#include <QShortcut>
#include <QWheelEvent>
#include <mybutton.h>

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

    QFile file;

    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void on_btn_save_clicked();
    void on_btn_close_clicked();
    void on_btn_edit_clicked();
    void mySlot();

    void on_btn_open_clicked();

    void onCurrentIndexChanged(int index);

    void onCursorPositionChanged();



signals:
    void mySignal();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
