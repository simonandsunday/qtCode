#include "readXml.h"
#include<QFile>
#include<QMessageBox>

#include<QDebug>
#define qDebugEx() qDebug()<<__func__<<__LINE__
namespace ns_Infinova_readXml{
readXml::readXml()
{
}

readXml::~readXml()
{

}

void readXml::readFile(QString path)
{
    if(path.isEmpty()){
        return;
    }
    QFile file(path);
    if(!file.open(QFile::ReadOnly|QFile::Text)){
        QMessageBox::information(NULL,QString("title"),QString("open error"));
        return;
    }
    QDomDocument document;
    QString error;
    int row=0,column=0;
    if(!document.setContent(&file,false,&error,&row,&column)){
        QMessageBox::information(NULL,QString("title"),QString("parse file failed at line row and column") + QString::number(row, 10) + QString(",") + QString::number(column, 10));
        return;
    }
    if(document.isNull()){
        QMessageBox::information(NULL,QString("title"),QString("document is null"));
        return;
    }
    QDomElement root=document.documentElement();
    parseElement(root);
}

void readXml::printData()
{
    QMap<QString,AreaInfo *>::const_iterator iter=m_areaInfoMap.constBegin();
    while(iter!=m_areaInfoMap.constEnd()){
        AreaInfo *item= iter.value();
        if(item->dwParentID()==QString("0")){
            qDebugEx()<<"find first area"<<item->dwAreaID();
            printAreaInfo(item);
        }
        ++iter;
    }
}

QMap<QString, AreaInfo*> readXml::getAreaInfoMap()
{
    return m_areaInfoMap;
}

void readXml::printAreaInfo(AreaInfo *data)
{
    qDebugEx()<<data->dwAreaID()<<data->cAreaName();
    QMap<QString,AreaInfo *> areaInfoChild=data->getChildAreaInfo();
    QMap<QString,DeviceInfo *> deviceInfoChild=data->getChildDeviceInfo();
    if(areaInfoChild.size()>0){
        QMap<QString,AreaInfo *>::const_iterator iter=areaInfoChild.constBegin();
        while(iter!=areaInfoChild.constEnd()){
            AreaInfo *item=iter.value();
            printAreaInfo(item);
            ++iter;
        }
    }
    if(deviceInfoChild.size()>0){
        QMap<QString,DeviceInfo *>::const_iterator iter=deviceInfoChild.constBegin();
        while(iter!=deviceInfoChild.constEnd()){
            DeviceInfo *item=iter.value();
            printDeviceInfo(item);
            ++iter;
        }
    }
    return;
}

void readXml::printDeviceInfo(DeviceInfo *data)
{
    qDebugEx()<<data->dwDevID()<<data->cDevName();
    QMap<QString,CameraInfo *> cameraInfoChild=data->getChildCameraInfo();
    if(cameraInfoChild.size()>0){
        QMap<QString,CameraInfo *>::const_iterator iter=cameraInfoChild.constBegin();
        while(iter!=cameraInfoChild.constEnd()){
            CameraInfo *item=iter.value();
            printCameraInfo(item);
            ++iter;
        }
    }
    return;
}

void readXml::printCameraInfo(CameraInfo *data)
{
    qDebugEx()<<data->dwCameraID()<<data->cCameraTitle();
}



void readXml::parseElement(QDomElement &item)
{
    QDomNamedNodeMap itemMap=item.attributes();
    QString itemName=item.tagName();
    QVariantHash itemData;
    for(int i=0;i<itemMap.size();i++){
        QDomNode mapItem=itemMap.item(i);
        qDebugEx()<<itemName<<mapItem.nodeName()<<mapItem.nodeValue();
        itemData.insert(mapItem.nodeName(),mapItem.nodeValue());
    }
    if(itemName==QString("CameraInfo")){
        CameraInfo *pInfo=new CameraInfo;
        pInfo->setData(itemData);
        m_cameraInfoMap.insert(pInfo->dwCameraID(),pInfo);
        if(m_deviceInfoMap.contains(pInfo->dwDevID())){
            //insert;
            DeviceInfo *parent=m_deviceInfoMap.value(pInfo->dwDevID());
            parent->setChildCameraInfo(pInfo->dwCameraID(),pInfo);
            m_deviceInfoMap.insert(pInfo->dwDevID(),parent);
        }
    }else if(itemName==QString("AreaInfo")){
        AreaInfo *pInfo=new AreaInfo;
        pInfo->setData(itemData);
        m_areaInfoMap.insert(pInfo->dwAreaID(),pInfo);
        if(m_areaInfoMap.contains(pInfo->dwParentID())){
            //insert
            AreaInfo *parent=m_areaInfoMap.value(pInfo->dwParentID());
            parent->setChildAreaInfo(pInfo->dwAreaID(),pInfo);
            m_areaInfoMap.insert(pInfo->dwParentID(),parent);
        }
    }else if(itemName==QString("DeviceInfo")){
        DeviceInfo *pInfo=new DeviceInfo;
        pInfo->setData(itemData);
        m_deviceInfoMap.insert(pInfo->dwDevID(),pInfo);
        if(m_areaInfoMap.contains(pInfo->dwAreaID())){
            AreaInfo *parent=m_areaInfoMap.value(pInfo->dwAreaID());
            parent->setChildDeviceInfo(pInfo->dwDevID(),pInfo);
            m_areaInfoMap.insert(pInfo->dwAreaID(),parent);
        }
    }


    QDomNodeList nodedList=item.childNodes();
    for(int i=0;i<nodedList.size();i++){
        QDomNode nodeItem=nodedList.at(i);
        if(nodeItem.isElement()){
            QDomElement element=nodeItem.toElement();
            parseElement(element);
        }
    }
}

readXmlTest::readXmlTest()
{

}

void readXmlTest::testReadFile()
{
    readXml entity;
    QString path=QString("C:/Qt/4.8.6/examples/xml/htmlinfo/Infinova_GetCameraList.xml");
    entity.readFile(path);
    entity.printData();
}

QString AreaInfo::dwAreaID()
{
    return m_data.value(__func__).toString();
}

QString AreaInfo::cAreaName()
{
    return m_data.value(__func__).toString();
}

QString AreaInfo::cMapName()
{
    return m_data.value(__func__).toString();
}

QString AreaInfo::dwParentID()
{
    return m_data.value(__func__).toString();
}

QString AreaInfo::dwAreaRank()
{
    return m_data.value(__func__).toString();
}

QString AreaInfo::cReserved()
{
    return m_data.value(__func__).toString();
}

void AreaInfo::setData(QString key, QString value)
{
    m_data.insert(key,value);
}

void AreaInfo::setData(QVariantHash &data)
{
    m_data.clear();
    m_data=data;
}

void AreaInfo::setChildAreaInfo(QString dwAreaID, AreaInfo *item)
{
    m_areaInfoChild.insert(dwAreaID,item);
}

void AreaInfo::setChildDeviceInfo(QString dwDevID, DeviceInfo *item)
{
    m_deviceInfoChild.insert(dwDevID,item);
}

QMap<QString, AreaInfo *> AreaInfo::getChildAreaInfo()
{
    return m_areaInfoChild;
}

QMap<QString, DeviceInfo *> AreaInfo::getChildDeviceInfo()
{
    return m_deviceInfoChild;
}

QString DeviceInfo::dwDevID()
{
    return m_data.value(__func__).toString();
}

QString DeviceInfo::cDevName()
{
    return m_data.value(__func__).toString();
}

QString DeviceInfo::cDevIP()
{
    return m_data.value(__func__).toString();
}

QString DeviceInfo::dwDevControlLevel()
{
    return m_data.value(__func__).toString();
}

QString DeviceInfo::dwAreaID()
{
    return m_data.value(__func__).toString();
}

QString DeviceInfo::dwDevType()
{
    return m_data.value(__func__).toString();
}

QString DeviceInfo::dwDevRight()
{
    return m_data.value(__func__).toString();
}

QString DeviceInfo::cDevUserName()
{
    return m_data.value(__func__).toString();
}

QString DeviceInfo::cDevPassword()
{
    return m_data.value(__func__).toString();
}

QString DeviceInfo::dwInputChan()
{
    return m_data.value(__func__).toString();
}

QString DeviceInfo::dwOutputChan()
{
    return m_data.value(__func__).toString();
}

QString DeviceInfo::cStreamType()
{
    return m_data.value(__func__).toString();
}

void DeviceInfo::setData(QString key, QString value)
{
    m_data.insert(key,value);
}

void DeviceInfo::setData(QVariantHash &data)
{
    m_data.clear();
    m_data=data;
}

void DeviceInfo::setChildCameraInfo(QString dwCameraID, CameraInfo *item)
{
    m_cameraInfoChild.insert(dwCameraID,item);
}

QMap<QString, CameraInfo *> DeviceInfo::getChildCameraInfo()
{
    return m_cameraInfoChild;
}

QString CameraInfo::dwCameraID()
{
    return m_data.value(__func__).toString();
}

QString CameraInfo::cCameraTitle()
{
    return m_data.value(__func__).toString();
}

QString CameraInfo::cCameraSIPID()
{
    return m_data.value(__func__).toString();
}

QString CameraInfo::dwDevID()
{
    return m_data.value(__func__).toString();
}

QString CameraInfo::dwDevChan()
{
    return m_data.value(__func__).toString();
}

QString CameraInfo::dwStatus()
{
    return m_data.value(__func__).toString();
}

QString CameraInfo::dwAux()
{
    return m_data.value(__func__).toString();
}

QString CameraInfo::dwProtocol()
{
    return m_data.value(__func__).toString();
}

QString CameraInfo::dwBaudRate()
{
    return m_data.value(__func__).toString();
}

QString CameraInfo::dwPTZID()
{
    return m_data.value(__func__).toString();
}

QString CameraInfo::cPTZIP()
{
    return m_data.value(__func__).toString();
}

void CameraInfo::setData(QString key, QString value)
{
    m_data.insert(key,value);
}

void CameraInfo::setData(QVariantHash &data)
{
    m_data.clear();
    m_data=data;
}

}
