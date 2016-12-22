/********************************************************************************
** Form generated from reading UI file 'phone.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHONE_H
#define UI_PHONE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_phone
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_auth;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_1;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *toolButton_7;
    QToolButton *toolButton_8;
    QToolButton *toolButton_9;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_5;
    QToolButton *toolButton_10;
    QToolButton *toolButton_0;
    QToolButton *toolButton_12;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *toolButton_audio;
    QToolButton *toolButton_video;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *phone)
    {
        if (phone->objectName().isEmpty())
            phone->setObjectName(QString::fromUtf8("phone"));
        phone->resize(291, 657);
        verticalLayout_2 = new QVBoxLayout(phone);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(phone);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("#widget{background-color: rgb(29, 41, 55);}\n"
"QPushButton{\n"
"    border: none;\n"
"    background-color: transparent;\n"
"	border-image: url(\"../images/ptzpanel/focus_zoom_lris/normal.png\");\n"
"    min-height: 26px;\n"
"    min-width: 35px;\n"
"	max-height: 26px;\n"
"    max-width: 35px;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QLabel { \n"
"\n"
"     font-weight: bold; \n"
"     color: white; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	border-image: url(\"../images/ptzpanel/focus_zoom_lris/hover.png\");\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"	border-image: url(\"../images/ptzpanel/focus_zoom_lris/pressed.png\");\n"
"}\n"
"QLineEdit{\n"
"background-color:rgb(50,62,78);\n"
"border-radius:3px;\n"
"border-color: rgb(83,95,109);\n"
"border-style: solid;\n"
"border-width:1px;\n"
"color:white;\n"
"}\n"
"\n"
"QLineEdit:focus {border-color: rgb(0, 111, 146);background-color: rgb(46, 68, 84);}\n"
""));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 9);
        lineEdit_auth = new QLineEdit(widget_4);
        lineEdit_auth->setObjectName(QString::fromUtf8("lineEdit_auth"));

        horizontalLayout_2->addWidget(lineEdit_auth);


        verticalLayout->addWidget(widget_4);

        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton_1 = new QToolButton(widget_5);
        toolButton_1->setObjectName(QString::fromUtf8("toolButton_1"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_1->sizePolicy().hasHeightForWidth());
        toolButton_1->setSizePolicy(sizePolicy);
        toolButton_1->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(toolButton_1);

        toolButton_2 = new QToolButton(widget_5);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        sizePolicy.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy);
        toolButton_2->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(widget_5);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        sizePolicy.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy);
        toolButton_3->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(toolButton_3);


        verticalLayout->addWidget(widget_5);

        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_3 = new QHBoxLayout(widget_6);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        toolButton_4 = new QToolButton(widget_6);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        sizePolicy.setHeightForWidth(toolButton_4->sizePolicy().hasHeightForWidth());
        toolButton_4->setSizePolicy(sizePolicy);
        toolButton_4->setMinimumSize(QSize(0, 25));

        horizontalLayout_3->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(widget_6);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolButton_5->sizePolicy().hasHeightForWidth());
        toolButton_5->setSizePolicy(sizePolicy1);
        toolButton_5->setMinimumSize(QSize(0, 25));

        horizontalLayout_3->addWidget(toolButton_5);

        toolButton_6 = new QToolButton(widget_6);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        sizePolicy.setHeightForWidth(toolButton_6->sizePolicy().hasHeightForWidth());
        toolButton_6->setSizePolicy(sizePolicy);
        toolButton_6->setMinimumSize(QSize(0, 25));

        horizontalLayout_3->addWidget(toolButton_6);


        verticalLayout->addWidget(widget_6);

        widget_7 = new QWidget(widget_2);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_4 = new QHBoxLayout(widget_7);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        toolButton_7 = new QToolButton(widget_7);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        sizePolicy1.setHeightForWidth(toolButton_7->sizePolicy().hasHeightForWidth());
        toolButton_7->setSizePolicy(sizePolicy1);
        toolButton_7->setMinimumSize(QSize(0, 25));

        horizontalLayout_4->addWidget(toolButton_7);

        toolButton_8 = new QToolButton(widget_7);
        toolButton_8->setObjectName(QString::fromUtf8("toolButton_8"));
        sizePolicy.setHeightForWidth(toolButton_8->sizePolicy().hasHeightForWidth());
        toolButton_8->setSizePolicy(sizePolicy);
        toolButton_8->setMinimumSize(QSize(0, 25));

        horizontalLayout_4->addWidget(toolButton_8);

        toolButton_9 = new QToolButton(widget_7);
        toolButton_9->setObjectName(QString::fromUtf8("toolButton_9"));
        sizePolicy.setHeightForWidth(toolButton_9->sizePolicy().hasHeightForWidth());
        toolButton_9->setSizePolicy(sizePolicy);
        toolButton_9->setMinimumSize(QSize(0, 25));

        horizontalLayout_4->addWidget(toolButton_9);


        verticalLayout->addWidget(widget_7);

        widget_8 = new QWidget(widget_2);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_5 = new QHBoxLayout(widget_8);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        toolButton_10 = new QToolButton(widget_8);
        toolButton_10->setObjectName(QString::fromUtf8("toolButton_10"));
        sizePolicy.setHeightForWidth(toolButton_10->sizePolicy().hasHeightForWidth());
        toolButton_10->setSizePolicy(sizePolicy);
        toolButton_10->setMinimumSize(QSize(0, 25));

        horizontalLayout_5->addWidget(toolButton_10);

        toolButton_0 = new QToolButton(widget_8);
        toolButton_0->setObjectName(QString::fromUtf8("toolButton_0"));
        sizePolicy.setHeightForWidth(toolButton_0->sizePolicy().hasHeightForWidth());
        toolButton_0->setSizePolicy(sizePolicy);
        toolButton_0->setMinimumSize(QSize(0, 25));

        horizontalLayout_5->addWidget(toolButton_0);

        toolButton_12 = new QToolButton(widget_8);
        toolButton_12->setObjectName(QString::fromUtf8("toolButton_12"));
        sizePolicy.setHeightForWidth(toolButton_12->sizePolicy().hasHeightForWidth());
        toolButton_12->setSizePolicy(sizePolicy);
        toolButton_12->setMinimumSize(QSize(0, 25));

        horizontalLayout_5->addWidget(toolButton_12);


        verticalLayout->addWidget(widget_8);

        widget_9 = new QWidget(widget_2);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_6 = new QHBoxLayout(widget_9);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 9, 0, 0);
        toolButton_audio = new QToolButton(widget_9);
        toolButton_audio->setObjectName(QString::fromUtf8("toolButton_audio"));
        sizePolicy.setHeightForWidth(toolButton_audio->sizePolicy().hasHeightForWidth());
        toolButton_audio->setSizePolicy(sizePolicy);
        toolButton_audio->setMinimumSize(QSize(0, 25));

        horizontalLayout_6->addWidget(toolButton_audio);

        toolButton_video = new QToolButton(widget_9);
        toolButton_video->setObjectName(QString::fromUtf8("toolButton_video"));
        sizePolicy.setHeightForWidth(toolButton_video->sizePolicy().hasHeightForWidth());
        toolButton_video->setSizePolicy(sizePolicy);
        toolButton_video->setMinimumSize(QSize(0, 25));

        horizontalLayout_6->addWidget(toolButton_video);


        verticalLayout->addWidget(widget_9);


        verticalLayout_3->addWidget(widget_2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("#widget_3{\n"
"border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: white;\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(widget_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget_11 = new QWidget(widget_3);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        horizontalLayout_7 = new QHBoxLayout(widget_11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, 0, -1, 0);
        label = new QLabel(widget_11);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_7->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);


        verticalLayout_4->addWidget(widget_11);

        widget_10 = new QWidget(widget_3);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout_9 = new QHBoxLayout(widget_10);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(-1, -1, -1, 0);
        label_2 = new QLabel(widget_10);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_9->addWidget(label_2);

        lineEdit = new QLineEdit(widget_10);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_9->addWidget(lineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);


        verticalLayout_4->addWidget(widget_10);

        widget_12 = new QWidget(widget_3);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        horizontalLayout_8 = new QHBoxLayout(widget_12);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(-1, -1, -1, 0);
        label_4 = new QLabel(widget_12);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_8->addWidget(label_4);

        lineEdit_2 = new QLineEdit(widget_12);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_8->addWidget(lineEdit_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);


        verticalLayout_4->addWidget(widget_12);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        verticalLayout_3->addWidget(widget_3);


        verticalLayout_2->addWidget(widget);


        retranslateUi(phone);

        QMetaObject::connectSlotsByName(phone);
    } // setupUi

    void retranslateUi(QWidget *phone)
    {
        phone->setWindowTitle(QApplication::translate("phone", "Form", 0, QApplication::UnicodeUTF8));
        toolButton_1->setText(QApplication::translate("phone", "1", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("phone", "2", 0, QApplication::UnicodeUTF8));
        toolButton_3->setText(QApplication::translate("phone", "3", 0, QApplication::UnicodeUTF8));
        toolButton_4->setText(QApplication::translate("phone", "4", 0, QApplication::UnicodeUTF8));
        toolButton_5->setText(QApplication::translate("phone", "5", 0, QApplication::UnicodeUTF8));
        toolButton_6->setText(QApplication::translate("phone", "6", 0, QApplication::UnicodeUTF8));
        toolButton_7->setText(QApplication::translate("phone", "7", 0, QApplication::UnicodeUTF8));
        toolButton_8->setText(QApplication::translate("phone", "8", 0, QApplication::UnicodeUTF8));
        toolButton_9->setText(QApplication::translate("phone", "9", 0, QApplication::UnicodeUTF8));
        toolButton_10->setText(QApplication::translate("phone", "*", 0, QApplication::UnicodeUTF8));
        toolButton_0->setText(QApplication::translate("phone", "0", 0, QApplication::UnicodeUTF8));
        toolButton_12->setText(QApplication::translate("phone", "#", 0, QApplication::UnicodeUTF8));
        toolButton_audio->setText(QApplication::translate("phone", "PushButton", 0, QApplication::UnicodeUTF8));
        toolButton_video->setText(QApplication::translate("phone", "PushButton", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("phone", "\347\224\250\346\210\267\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("phone", "\345\247\223\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("phone", "\345\217\267\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class phone: public Ui_phone {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHONE_H
