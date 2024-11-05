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
    // QObject::connect(ui->btn_open, &QPushButton::clicked, [=](){
    //     qDebug() << "btn open clicked().";
    // });
    //第四种方式
    QObject::connect(ui->btn_edit, &QPushButton::clicked, this, &Widget::on_btn_edit_clicked);
    //自定义信号与槽
    QObject::connect(this, SIGNAL(mySignal()), this, SLOT(mySlot()));
    //下拉框
    QObject::connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onCurrentIndexChanged(int)));
    emit mySignal();

    //捕捉光标改变的信号
    QObject::connect(ui->plainTextEdit, SIGNAL(cursorPositionChanged()), this, SLOT(onCursorPositionChanged()));

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

    //打开文件
    QFile file("C:\\Users\\codefish\\Desktop\\openfile.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "file open failed.";
    };
    //写入文件
    // if(file.write("This is my first qt program.") == -1)
    // {
    //     qDebug() << "write failed.";
    // };
    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);
    out << "I love u, 我爱你!";
    //关闭
    file.close();
    qDebug() << "write succ.";
}

void Widget::on_btn_close_clicked()
{
    time_t now = time(0);
    char* time_str = ctime(&now);
    qDebug() << "close btn clicked()." << time_str;
    this->setWindowTitle("记事本");
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

void Widget::on_btn_open_clicked()
{
    qDebug() << "文件打开.";
    ui->plainTextEdit->clear();
    QString fileName = QFileDialog::getOpenFileName(this, tr("选择文件"), "D://QT", tr("文本文件(*.txt)"));
    if(fileName.isNull())
    {
        qDebug() << "getOpenFileName err";
        return;
    }
    this->setWindowTitle(fileName + "-记事本");
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "file open err";
        return;
    }

    // const uchar* contents = file.map(0, file.size());
    // const QString data = QString::fromUtf8(reinterpret_cast<const char*>(contents), file.size());
    QTextDocument document;
    QElapsedTimer timer;
    timer.restart();
    QTextStream in(&file);
    in.setEncoding(QStringConverter::Utf8);
    QString line = in.readAll();
    qDebug() << "loading document of " << line.length()/1e6 << " MiB took " << timer.elapsed()/1e3 << "seconds.";
    ui->plainTextEdit->setWordWrapMode(QTextOption::WrapAnywhere);
    ui->plainTextEdit->setPlainText(line);
    qDebug() << "here!";
}

void Widget::onCurrentIndexChanged(int index)
{
    qDebug() << "index";
    qDebug().noquote() << ui->comboBox->currentText();
    QString str = "hello world";
    auto placeholder = str.toStdString();
    const char *ch = placeholder.c_str();
    qDebug() << ch;
}

void Widget::onCursorPositionChanged()
{
    qDebug() << "cursor changed.";
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    qDebug() << "col:" << cursor.columnNumber() << "row:" << cursor.blockNumber();
    QString blockNum = QString::number(cursor.blockNumber());
    QString columnNum = QString::number(cursor.columnNumber());
    const QString lableMsg = "L: " + blockNum + " C: " + columnNum;
    ui->btn_label->setText(lableMsg);
    //设置当前行高亮
    QList<QTextEdit::ExtraSelection> extras;
    QTextEdit::ExtraSelection ext;
    //1.获取当前行
    ext.cursor = cursor;
    //2.颜色
    ext.format.setBackground(QBrush(Qt::yellow));
    ext.format.setProperty(QTextFormat::FullWidthSelection, true);
    //3.设置
    extras.append(ext);
    ui->plainTextEdit->setExtraSelections(extras);
}


