/********************************************************************************
** Form generated from reading UI file 'testToolBox.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTTOOLBOX_H
#define UI_TESTTOOLBOX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testToolBox
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;

    void setupUi(QWidget *testToolBox)
    {
        if (testToolBox->objectName().isEmpty())
            testToolBox->setObjectName(QString::fromUtf8("testToolBox"));
        testToolBox->resize(400, 300);
        gridLayout = new QGridLayout(testToolBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(testToolBox);
        widget->setObjectName(QString::fromUtf8("widget"));

        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(testToolBox);

        QMetaObject::connectSlotsByName(testToolBox);
    } // setupUi

    void retranslateUi(QWidget *testToolBox)
    {
        testToolBox->setWindowTitle(QApplication::translate("testToolBox", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class testToolBox: public Ui_testToolBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTTOOLBOX_H
