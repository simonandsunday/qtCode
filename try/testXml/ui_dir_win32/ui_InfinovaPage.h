/********************************************************************************
** Form generated from reading UI file 'InfinovaPage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFINOVAPAGE_H
#define UI_INFINOVAPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfinovaPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_4;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_platformName;
    QLabel *label_3;
    QLineEdit *lineEdit_userName;
    QLabel *label_2;
    QLineEdit *lineEdit_serviceIp;
    QLabel *label_4;
    QLineEdit *lineEdit_password;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton;
    QSpacerItem *verticalSpacer;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QTreeWidget *treeWidget;
    QWidget *widget_info;

    void setupUi(QWidget *InfinovaPage)
    {
        if (InfinovaPage->objectName().isEmpty())
            InfinovaPage->setObjectName(QString::fromUtf8("InfinovaPage"));
        InfinovaPage->resize(533, 506);
        verticalLayout = new QVBoxLayout(InfinovaPage);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(InfinovaPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout = new QGridLayout(widget_4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget_4);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_platformName = new QLineEdit(widget_4);
        lineEdit_platformName->setObjectName(QString::fromUtf8("lineEdit_platformName"));

        gridLayout->addWidget(lineEdit_platformName, 0, 1, 1, 1);

        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        lineEdit_userName = new QLineEdit(widget_4);
        lineEdit_userName->setObjectName(QString::fromUtf8("lineEdit_userName"));

        gridLayout->addWidget(lineEdit_userName, 0, 3, 1, 1);

        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_serviceIp = new QLineEdit(widget_4);
        lineEdit_serviceIp->setObjectName(QString::fromUtf8("lineEdit_serviceIp"));

        gridLayout->addWidget(lineEdit_serviceIp, 1, 1, 1, 1);

        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        lineEdit_password = new QLineEdit(widget_4);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));

        gridLayout->addWidget(lineEdit_password, 1, 3, 1, 1);


        horizontalLayout->addWidget(widget_4);

        horizontalSpacer = new QSpacerItem(21, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton = new QToolButton(widget_2);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setMinimumSize(QSize(40, 40));

        horizontalLayout->addWidget(toolButton);


        verticalLayout_2->addWidget(widget_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        treeWidget = new QTreeWidget(widget_3);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setMinimumSize(QSize(250, 200));
        treeWidget->setMaximumSize(QSize(250, 200));

        horizontalLayout_2->addWidget(treeWidget);

        widget_info = new QWidget(widget_3);
        widget_info->setObjectName(QString::fromUtf8("widget_info"));

        horizontalLayout_2->addWidget(widget_info);


        verticalLayout_2->addWidget(widget_3);


        verticalLayout->addWidget(widget);


        retranslateUi(InfinovaPage);

        QMetaObject::connectSlotsByName(InfinovaPage);
    } // setupUi

    void retranslateUi(QWidget *InfinovaPage)
    {
        InfinovaPage->setWindowTitle(QApplication::translate("InfinovaPage", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("InfinovaPage", "\345\271\263\345\217\260\345\220\215\347\247\260\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("InfinovaPage", "\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("InfinovaPage", "\346\234\215\345\212\241\345\231\250IP\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("InfinovaPage", "\347\224\250\346\210\267\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("InfinovaPage", "serach", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InfinovaPage: public Ui_InfinovaPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFINOVAPAGE_H
