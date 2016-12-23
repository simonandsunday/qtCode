#include "phone.h"
#include "ui_phone.h"
#include<QDebug>
#define qDebugEx() qDebug()<<__func__<<__LINE__
phone::phone(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::phone)
{
    ui->setupUi(this);
    ui->lineEdit->setDisabled(true);
    ui->lineEdit_2->setDisabled(true);
}

phone::~phone()
{
    delete ui;
}



void phone::on_toolButton_1_clicked()
{
    qDebugEx();
    QString data= ui->lineEdit_auth->text();
    data=data.append("1");
    ui->lineEdit_auth->setText(data);
}

void phone::on_toolButton_2_clicked()
{
    qDebugEx();
    QString data= ui->lineEdit_auth->text();
    data=data.append("2");
    ui->lineEdit_auth->setText(data);
}

void phone::on_toolButton_3_clicked()
{
    qDebugEx();
    QString data= ui->lineEdit_auth->text();
    data=data.append("3");
    ui->lineEdit_auth->setText(data);
}

void phone::on_toolButton_4_clicked()
{
    qDebugEx();
    QString data= ui->lineEdit_auth->text();
    data=data.append("4");
    ui->lineEdit_auth->setText(data);
}

void phone::on_toolButton_5_clicked()
{
    qDebugEx();
    QString data= ui->lineEdit_auth->text();
    data=data.append("5");
    ui->lineEdit_auth->setText(data);
}

void phone::on_toolButton_6_clicked()
{
    qDebugEx();
    QString data= ui->lineEdit_auth->text();
    data=data.append("6");
    ui->lineEdit_auth->setText(data);
}

void phone::on_toolButton_7_clicked()
{
    qDebugEx();
    QString data= ui->lineEdit_auth->text();
    data=data.append("7");
    ui->lineEdit_auth->setText(data);
}

void phone::on_toolButton_8_clicked()
{
    qDebugEx();
    QString data= ui->lineEdit_auth->text();
    data=data.append("8");
    ui->lineEdit_auth->setText(data);
}

void phone::on_toolButton_9_clicked()
{
    qDebugEx();
    QString data= ui->lineEdit_auth->text();
    data=data.append("9");
    ui->lineEdit_auth->setText(data);
}

void phone::on_toolButton_0_clicked()
{
    qDebugEx();
    QString data= ui->lineEdit_auth->text();
    data=data.append("0");
    ui->lineEdit_auth->setText(data);
}

void phone::on_toolButton_10_clicked()
{
    qDebugEx();
    QString data= ui->lineEdit_auth->text();
    data=data.append("*");
    ui->lineEdit_auth->setText(data);
}

void phone::on_toolButton_12_clicked()
{
    qDebugEx();
    QString data= ui->lineEdit_auth->text();
    data=data.append("#");
    ui->lineEdit_auth->setText(data);
}

void phone::on_toolButton_audio_clicked()
{
    qDebugEx();
}

void phone::on_toolButton_video_clicked()
{
    qDebugEx();
}

void phone::on_toolButton_clicked()
{
    qDebugEx();
    QString data= ui->lineEdit_auth->text();
    if(data.size()>0){
        data=data.remove(data.size()-1,1);
    }
    ui->lineEdit_auth->setText(data);
}
