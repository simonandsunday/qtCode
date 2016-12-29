#include "AreaWidget.h"
#include "ui_AreaWidget.h"

AreaWidget::AreaWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AreaWidget)
{
    ui->setupUi(this);
}

AreaWidget::~AreaWidget()
{
    delete ui;
}

void AreaWidget::setData(ns_Infinova_readXml::AreaInfo *item)
{
    ui->lineEdit_cAreaName->setText(item->cAreaName());
    ui->lineEdit_cMapName->setText(item->cMapName());
    ui->lineEdit_cReserved->setText(item->cReserved());
    ui->lineEdit_dwAreaID->setText(item->dwAreaID());
    ui->lineEdit_dwAreaRank->setText(item->dwAreaRank());
    ui->lineEdit_dwParentID->setText(item->dwParentID());
}
