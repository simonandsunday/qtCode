#include "InfinovaPage.h"
#include "ui_InfinovaPage.h"
#include"readXml.h"
#include<QDebug>
#include<QVBoxLayout>
#include"AreaWidget.h"
#include"DeviceWidget.h"
#include"cameraWidget.h"
#define Infinova_tree_Item_data_role (Qt::SizeHintRole+1000)
#define Infinova_tree_Item_type_role (Qt::SizeHintRole+1001)
#define qDebugEx() qDebug()<<__func__<<__LINE__
InfinovaPage::InfinovaPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfinovaPage)
{
    ui->setupUi(this);
    QVBoxLayout *layout=new QVBoxLayout;
    ui->widget_info->setLayout(layout);
    connect(ui->treeWidget,SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)),this,SLOT(currentItemChangedSlot(QTreeWidgetItem*,QTreeWidgetItem*)));
    ui->treeWidget->setHeaderLabel("区域");
}

InfinovaPage::~InfinovaPage()
{
    delete ui;
}

void InfinovaPage::on_toolButton_clicked()
{
    ns_Infinova_readXml::readXml entity;
    QString path=QString("C:/Qt/4.8.6/examples/xml/htmlinfo/Infinova_GetCameraList.xml");
    entity.readFile(path);
    //entity.printData();
    ui->treeWidget->clear();
    QMap<QString,ns_Infinova_readXml::AreaInfo*> areaInfoMap=entity.getAreaInfoMap();
    initTree(areaInfoMap);
}

void InfinovaPage::currentItemChangedSlot(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    if(current==NULL){
        return;
    }
    int type=current->data(0,Infinova_tree_Item_type_role).toInt();

    qDebugEx()<<"change"<<type;
    if(type==areaInfo_type){
        ui->treeWidget->setHeaderLabel(QString("区域"));
        QVariant value=current->data(0,Infinova_tree_Item_data_role);
        if(value.isNull()){
            return;
        }
        ns_Infinova_readXml::AreaInfo *data=value.value<ns_Infinova_readXml::AreaInfo *>();
        if(data==NULL){
            return;
        }
        qDebugEx()<<data->cAreaName();
        AreaWidget *areaUi=new AreaWidget;
        areaUi->setData(data);
        QVBoxLayout *layout=(QVBoxLayout*)ui->widget_info->layout();
        if(layout!=NULL){
            while(layout->count()){
                QLayoutItem *layoutItem=layout->itemAt(0);
                layoutItem->widget()->hide();
                layout->removeWidget(layoutItem->widget());
            }
            delete layout;
        }
        QVBoxLayout *newLayout=new QVBoxLayout;
        newLayout->addWidget(areaUi);
        ui->widget_info->setLayout(newLayout);
        ui->widget_info->repaint();
    }else if(type==deviceInfo_type){
        QVariant value=current->data(0,Infinova_tree_Item_data_role);
        ui->treeWidget->setHeaderLabel(QString("设备"));
        if(value.isNull()){
            return;
        }
        ns_Infinova_readXml::DeviceInfo *data=value.value<ns_Infinova_readXml::DeviceInfo *>();
        if(data==NULL){
            return;
        }
        qDebugEx()<<data->cDevName();
        DeviceWidget *deviceUi=new DeviceWidget;
        QVBoxLayout *layout=(QVBoxLayout*)ui->widget_info->layout();
        if(layout!=NULL){
            while(layout->count()){
                QLayoutItem *layoutItem=layout->itemAt(0);
                layoutItem->widget()->hide();
                layout->removeWidget(layoutItem->widget());
            }
            delete layout;
        }
        QVBoxLayout *newLayout=new QVBoxLayout;
        deviceUi->setData(data);
        newLayout->addWidget(deviceUi);
        ui->widget_info->setLayout(newLayout);
    }else if(type==cameraInfo_type){
        ui->treeWidget->setHeaderLabel(QString("通道"));
        QVariant value=current->data(0,Infinova_tree_Item_data_role);
        if(value.isNull()){
            return;
        }
        ns_Infinova_readXml::CameraInfo *data=value.value<ns_Infinova_readXml::CameraInfo *>();
        if(data==NULL){
            return;
        }
        qDebugEx()<<data->cCameraTitle();
        cameraWidget *cameraUi=new cameraWidget;
        QVBoxLayout *layout=(QVBoxLayout*)ui->widget_info->layout();
        if(layout!=NULL){
            while(layout->count()){
                QLayoutItem *layoutItem=layout->itemAt(0);
                layoutItem->widget()->hide();
                layout->removeWidget(layoutItem->widget());
            }
            delete layout;
        }
        QVBoxLayout *newLayout=new QVBoxLayout;
        cameraUi->setData(data);
        newLayout->addWidget(cameraUi);
        ui->widget_info->setLayout(newLayout);
    }
}

void InfinovaPage::initTree(QMap<QString, ns_Infinova_readXml::AreaInfo *> AreaInfoMap)
{
    QMap<QString,ns_Infinova_readXml::AreaInfo *>::const_iterator iter=AreaInfoMap.constBegin();
    while(iter!=AreaInfoMap.constEnd()){
        ns_Infinova_readXml::AreaInfo *item= iter.value();
        if(item->dwParentID()==QString("0")){
            QTreeWidgetItem *treeItem=new QTreeWidgetItem((QTreeWidgetItem*)NULL,QStringList(item->cAreaName()));
            treeItem->setData(0,Infinova_tree_Item_data_role,QVariant::fromValue(item));
            treeItem->setData(0,Infinova_tree_Item_type_role,areaInfo_type);
            ui->treeWidget->insertTopLevelItem(0,treeItem);
            initArea(item,treeItem);
        }
        ++iter;
    }
}

void InfinovaPage::initArea(ns_Infinova_readXml::AreaInfo *item, QTreeWidgetItem *parent)
{
    QMap<QString,ns_Infinova_readXml::AreaInfo*> areaInfoChild=item->getChildAreaInfo();
    QMap<QString,ns_Infinova_readXml::DeviceInfo *> deviceInfoChild=item->getChildDeviceInfo();
    QMap<QString,ns_Infinova_readXml::AreaInfo*>::const_iterator iter=areaInfoChild.constBegin();
    while(iter!=areaInfoChild.constEnd()){
        ns_Infinova_readXml::AreaInfo* areaItem=iter.value();
        QTreeWidgetItem *treeItem=new QTreeWidgetItem(parent,QStringList(areaItem->cAreaName()));
        treeItem->setData(0,Infinova_tree_Item_data_role,QVariant::fromValue(areaItem));
        treeItem->setData(0,Infinova_tree_Item_type_role,areaInfo_type);
        initArea(areaItem,treeItem);
        ++iter;
    }
    QMap<QString,ns_Infinova_readXml::DeviceInfo *>::const_iterator iter1=deviceInfoChild.constBegin();
    while(iter1!=deviceInfoChild.constEnd()){
        ns_Infinova_readXml::DeviceInfo * deviceItem=iter1.value();
        QTreeWidgetItem *treeItem=new QTreeWidgetItem(parent,QStringList(deviceItem->cDevName()));
        treeItem->setData(0,Infinova_tree_Item_data_role,QVariant::fromValue(deviceItem));
        treeItem->setData(0,Infinova_tree_Item_type_role,deviceInfo_type);
        initDevice(deviceItem,treeItem);
        ++iter1;
    }
}

void InfinovaPage::initDevice(ns_Infinova_readXml::DeviceInfo *item, QTreeWidgetItem *parent)
{
    QMap<QString,ns_Infinova_readXml::CameraInfo*> cameraInfoChild=item->getChildCameraInfo();
    QMap<QString,ns_Infinova_readXml::CameraInfo*>::const_iterator iter=cameraInfoChild.constBegin();
    while(iter!=cameraInfoChild.constEnd()){
        ns_Infinova_readXml::CameraInfo *cameraItem=iter.value();
        QTreeWidgetItem *treeItem=new QTreeWidgetItem(parent,QStringList(cameraItem->cCameraTitle()));
        treeItem->setData(0,Infinova_tree_Item_data_role,QVariant::fromValue(cameraItem));
        treeItem->setData(0,Infinova_tree_Item_type_role,cameraInfo_type);
        initCamera(cameraItem,treeItem);
        ++iter;
    }
}

void InfinovaPage::initCamera(ns_Infinova_readXml::CameraInfo *item, QTreeWidgetItem *parent)
{
    //QTreeWidgetItem *treeItem=new QTreeWidgetItem(parent,QStringList(item->));
}
