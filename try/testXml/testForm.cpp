#include "testForm.h"
#include "ui_testForm.h"
#include<QDebug>
#include"AreaWidget.h"
#include"DeviceWidget.h"
#include<QVBoxLayout>
testForm::testForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::testForm)
{
    ui->setupUi(this);
    QStringList list;
    list<<"1"<<"2";
    ui->comboBox->addItems(list);
    QVBoxLayout *layout=new QVBoxLayout;
    AreaWidget *item=new AreaWidget;
    layout->addWidget(item);
    ui->widget_info->setLayout(layout);
}

testForm::~testForm()
{
    delete ui;
}

void testForm::on_comboBox_currentIndexChanged(const QString &arg1)
{
    qDebug()<<__func__<<__LINE__<<arg1;
    if(arg1==QString("1")){
        QLayout *layout=ui->widget_info->layout();
        if(layout==NULL){
            return;
        }
        while(layout->count()){
            QLayoutItem *item=layout->itemAt(0);
            item->widget()->hide();
            layout->removeWidget(item->widget());
        }

        delete layout;
        QVBoxLayout *newLayout=new QVBoxLayout;
        AreaWidget *item=new AreaWidget;
        newLayout->addWidget(item);
        ui->widget_info->setLayout(newLayout);
    }else{
        QLayout *layout=ui->widget_info->layout();
        if(layout==NULL){
            return;
        }
        while(layout->count()){
            QLayoutItem *item=layout->itemAt(0);
            item->widget()->hide();
            layout->removeWidget(item->widget());
        }
        delete layout;
        QVBoxLayout *newLayout=new QVBoxLayout;
        DeviceWidget *item=new DeviceWidget;
        newLayout->addWidget(item);
        ui->widget_info->setLayout(newLayout);
    }
}
