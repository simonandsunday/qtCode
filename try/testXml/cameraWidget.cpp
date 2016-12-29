#include "cameraWidget.h"
#include "ui_cameraWidget.h"

cameraWidget::cameraWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cameraWidget)
{
    ui->setupUi(this);
}

cameraWidget::~cameraWidget()
{
    delete ui;
}

void cameraWidget::setData(ns_Infinova_readXml::CameraInfo *data)
{
    ui->lineEdit_cCameraSIPID->setText(data->cCameraSIPID());
    ui->lineEdit_cCameraTitle->setText(data->cCameraTitle());
    ui->lineEdit_cPTZIP->setText(data->cPTZIP());
    ui->lineEdit_dwAux->setText(data->dwAux());
    ui->lineEdit_dwBaudRate->setText(data->dwBaudRate());
    ui->lineEdit_dwCameraID->setText(data->dwCameraID());
    ui->lineEdit_dwDevChan->setText(data->dwDevChan());
    ui->lineEdit_dwDevID->setText(data->dwDevID());
    ui->lineEdit_dwProtocol->setText(data->dwProtocol());
    ui->lineEdit_dwPTZID->setText(data->dwPTZID());
    ui->lineEdit_dwStatus->setText(data->dwStatus());
}
