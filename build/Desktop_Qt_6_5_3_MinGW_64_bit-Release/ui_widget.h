/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_save;
    QPushButton *btn_close;
    QPushButton *btn_open;
    QPushButton *btn_edit;
    QSpacerItem *horizontalSpacer;
    QTextEdit *textEdit;
    QFrame *frame_2;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        Widget->setStyleSheet(QString::fromUtf8(" QComboBox QAbstractItemView {\n"
"	background-image: url(:/icon/Fearless Wallpaper Desktop Version 4k Resolution R Taylorswift.jpg);\n"
"     border: 2px solid darkgray;\n"
"     selection-background-color: lightgray;\n"
" }\n"
""));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 801, 601));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(layoutWidget);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(0, 50));
        frame->setMaximumSize(QSize(16777215, 500));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        layoutWidget1 = new QWidget(frame);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(30, 10, 371, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_save = new QPushButton(layoutWidget1);
        btn_save->setObjectName("btn_save");
        btn_save->setStyleSheet(QString::fromUtf8(" QPushButton { color: red; background-color: white }\n"
""));

        horizontalLayout->addWidget(btn_save);

        btn_close = new QPushButton(layoutWidget1);
        btn_close->setObjectName("btn_close");
        btn_close->setStyleSheet(QString::fromUtf8(" QPushButton { color: red; background-color: white }\n"
""));

        horizontalLayout->addWidget(btn_close);

        btn_open = new QPushButton(layoutWidget1);
        btn_open->setObjectName("btn_open");
        btn_open->setStyleSheet(QString::fromUtf8(" QPushButton { color: red; background-color: white }"));

        horizontalLayout->addWidget(btn_open);

        btn_edit = new QPushButton(layoutWidget1);
        btn_edit->setObjectName("btn_edit");
        btn_edit->setStyleSheet(QString::fromUtf8(" QPushButton { color: red; background-color: white }"));

        horizontalLayout->addWidget(btn_edit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(frame);

        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName("textEdit");
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(138, 138, 138, 50);\n"
""));

        verticalLayout->addWidget(textEdit);

        frame_2 = new QFrame(layoutWidget);
        frame_2->setObjectName("frame_2");
        frame_2->setMinimumSize(QSize(0, 50));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 127);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        layoutWidget2 = new QWidget(frame_2);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(430, 20, 112, 18));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        label = new QLabel(layoutWidget2);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);


        verticalLayout->addWidget(frame_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        btn_save->setText(QCoreApplication::translate("Widget", "\344\277\235\345\255\230", nullptr));
        btn_close->setText(QCoreApplication::translate("Widget", "\345\205\263\351\227\255", nullptr));
        btn_open->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200", nullptr));
        btn_edit->setText(QCoreApplication::translate("Widget", "\347\274\226\350\276\221", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\347\254\254\344\270\200\350\241\214\347\254\254\344\270\200\345\210\227", nullptr));
        label->setText(QCoreApplication::translate("Widget", "UTF-8", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
