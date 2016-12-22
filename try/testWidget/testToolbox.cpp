#include "testToolBox.h"
#include "ui_testToolBox.h"
#include<QDebug>
#include<QHBoxLayout>
#include<QToolBox>
#include"phone.h"
testToolBox::testToolBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::testToolBox)
{
    ui->setupUi(this);

    QHBoxLayout *layout=new QHBoxLayout;
    QToolBox *toolbox=new QToolBox;
    toolbox->addItem(new phone,QString("sdfdsf"));

    QToolBox *toolbox1=new QToolBox;
    toolbox1->addItem(new phone,QString("2_1"));
    toolbox1->addItem(new phone,QString("2_2"));
    toolbox->addItem(toolbox1,"2");
    toolbox->addItem(new phone,QString("dsf"));
    layout->addWidget(toolbox);
    ui->widget->setLayout(layout);

}

testToolBox::~testToolBox()
{
    delete ui;
}
