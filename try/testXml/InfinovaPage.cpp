#include "InfinovaPage.h"
#include "ui_InfinovaPage.h"
#include"readXml.h"
#include<QDebug>
#define Infinova_tree_Item_data_role (Qt::SizeHintRole+1000)
#define Infinova_tree_Item_type_role (Qt::SizeHintRole+1001)
#define qDebugEx() qDebug()<<__func__<<__LINE__
InfinovaPage::InfinovaPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfinovaPage)
{
    ui->setupUi(this);
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

void InfinovaPage::initTree(QMap<QString, ns_Infinova_readXml::AreaInfo *> AreaInfoMap)
{
    QMap<QString,ns_Infinova_readXml::AreaInfo *>::const_iterator iter=AreaInfoMap.constBegin();
    while(iter!=AreaInfoMap.constEnd()){
        ns_Infinova_readXml::AreaInfo *item= iter.value();
        if(item->dwParentID()==QString("0")){
            QTreeWidgetItem *treeItem=new QTreeWidgetItem((QTreeWidgetItem*)NULL,QStringList(item->cAreaName()));
            treeItem->setData(0,Infinova_tree_Item_data_role,item);
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
        treeItem->setData(0,Infinova_tree_Item_data_role,areaItem);
        treeItem->setData(0,Infinova_tree_Item_type_role,areaInfo_type);
        initArea(areaItem,treeItem);
        ++iter;
    }
    QMap<QString,ns_Infinova_readXml::DeviceInfo *>::const_iterator iter1=deviceInfoChild.constBegin();
    while(iter1!=deviceInfoChild.constEnd()){
        ns_Infinova_readXml::DeviceInfo * deviceItem=iter1.value();
        QTreeWidgetItem *treeItem=new QTreeWidgetItem(parent,QStringList(deviceItem->cDevName()));
        treeItem->setData(0,Infinova_tree_Item_data_role,deviceItem);
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
        treeItem->setData(0,Infinova_tree_Item_data_role,cameraItem);
        treeItem->setData(0,Infinova_tree_Item_type_role,cameraInfo_type);
        initCamera(cameraItem,treeItem);
        ++iter;
    }
}

void InfinovaPage::initCamera(ns_Infinova_readXml::CameraInfo *item, QTreeWidgetItem *parent)
{
    //QTreeWidgetItem *treeItem=new QTreeWidgetItem(parent,QStringList(item->));
}
