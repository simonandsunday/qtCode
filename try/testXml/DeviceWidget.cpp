#include "DeviceWidget.h"
#include "ui_DeviceWidget.h"

DeviceWidget::DeviceWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceWidget)
{
    ui->setupUi(this);
}

DeviceWidget::~DeviceWidget()
{
    delete ui;
}

void DeviceWidget::setData(ns_Infinova_readXml::DeviceInfo *data)
{
    ui->lineEdit_cDevIP->setText(data->cDevIP());
    ui->lineEdit_cDevName->setText(data->cDevName());
    ui->lineEdit_cDevPassword->setText(data->cDevPassword());
    ui->lineEdit_cDevUserName->setText(data->cDevUserName());
    ui->lineEdit_cStreamType->setText(data->cStreamType());
    ui->lineEdit_dwAreaID->setText(data->dwAreaID());
    ui->lineEdit_dwDevControlLevel->setText(data->dwDevControlLevel());
    ui->lineEdit_dwDevID->setText(data->dwDevID());
    ui->lineEdit_dwDevRight->setText(data->dwDevRight());
    ui->lineEdit_dwDevType->setText(data->dwDevType());
    ui->lineEdit_dwInputChan->setText(data->dwInputChan());
    ui->lineEdit_dwOutputChan->setText(data->dwOutputChan());
}
