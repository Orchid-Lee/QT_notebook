#include "widget.h"
#include "ui_widget.h"
#include <time.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //第二种方式 Object::connect(sender, SIGNAL(signal()), receiver, SLOT(slot()));
    QObject::connect(ui->btn_close, SIGNAL(clicked()), this, SLOT(on_btn_close_clicked));
    //第三种方式 lambda表达式：QObject::connect(sender, &Sender::signal, [=](){ /* lambda body */ })
    QObject::connect(ui->btn_open, &QPushButton::clicked, [=](){
        std::cout << "btn open clicked()." << std::endl;
    });
    //第四种方式
    QObject::connect(ui->btn_edit, &QPushButton::clicked, this, &Widget::on_btn_edit_clicked);
    //自定义信号与槽
    QObject::connect(this, SIGNAL(mySignal()), this, SLOT(mySlot()));
    emit mySignal();
    this->setLayout(ui->verticalLayout);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btn_save_clicked()
{
    time_t now = time(0);
    char* time_str = ctime(&now);
    qDebug() << "save btn clicked()." << time_str;
}

void Widget::on_btn_close_clicked()
{
    time_t now = time(0);
    char* time_str = ctime(&now);
    qDebug() << "close btn clicked()." << time_str;
}

void Widget::on_btn_edit_clicked()
{
    time_t now = time(0);
    char* time_str = ctime(&now);
    qDebug() << "edit btn clicked()." << time_str;
}

void Widget::mySlot()
{
    qDebug() << "This is a customer slot.";
}
