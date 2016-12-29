#ifndef READXML_H
#define READXML_H
#include<QString>
#include<QDomDocument>
#include<QMap>
#include<QVariantHash>

namespace ns_Infinova_readXml{


class CameraInfo{
public:
    QString dwCameraID();
    QString cCameraTitle();
    QString cCameraSIPID();
    QString dwDevID();
    QString dwDevChan();
    QString dwStatus();
    QString dwAux();
    QString dwProtocol();
    QString dwBaudRate();
    QString dwPTZID();
    QString cPTZIP();
    void setData(QString key,QString value);
    void setData(QVariantHash &data);
private:
    QVariantHash m_data;
};
class DeviceInfo{
public:
   QString dwDevID();
   QString cDevName();
   QString cDevIP();
   QString dwDevControlLevel();
   QString dwAreaID();
   QString dwDevType();
   QString dwDevRight();
   QString cDevUserName();
   QString cDevPassword();
   QString dwInputChan();
   QString dwOutputChan();
   QString cStreamType();
   void setData(QString key,QString value);
   void setData(QVariantHash &data);
   void setChildCameraInfo(QString dwCameraID,CameraInfo *item);
   QMap<QString ,CameraInfo *> getChildCameraInfo();
private:
    QVariantHash m_data;
    QMap<QString ,CameraInfo *> m_cameraInfoChild;
};
class AreaInfo{
public:
    QString dwAreaID();
    QString cAreaName();
    QString cMapName();
    QString dwParentID();
    QString dwAreaRank();
    QString cReserved();
    void setData(QString key,QString value);
    void setData(QVariantHash &data);
    void setChildAreaInfo(QString dwAreaID,AreaInfo *item);
    void setChildDeviceInfo(QString dwDevID,DeviceInfo *item);
    QMap<QString ,AreaInfo*> getChildAreaInfo();
    QMap<QString, DeviceInfo *> getChildDeviceInfo();
private:
    QVariantHash m_data;
    QMap<QString,AreaInfo *> m_areaInfoChild;
    QMap<QString ,DeviceInfo *> m_deviceInfoChild;
};
class readXmlTest{
public:
    readXmlTest();
    static void testReadFile();

};
class readXml
{
public:
    readXml();
    ~readXml();
    void readFile(QString path);
    void printData();
    QMap<QString,AreaInfo*> getAreaInfoMap();
private:
    void parseElement(QDomElement &item);
    void printAreaInfo(AreaInfo *data);
    void printDeviceInfo(DeviceInfo *data);
    void printCameraInfo(CameraInfo *data);
private:
    QMap<QString, CameraInfo *> m_cameraInfoMap;
    QMap<QString,DeviceInfo *> m_deviceInfoMap;
    QMap<QString,AreaInfo *> m_areaInfoMap;
};
}
Q_DECLARE_METATYPE(ns_Infinova_readXml::AreaInfo)
Q_DECLARE_METATYPE(ns_Infinova_readXml::DeviceInfo)
Q_DECLARE_METATYPE(ns_Infinova_readXml::CameraInfo)
Q_DECLARE_METATYPE(ns_Infinova_readXml::AreaInfo *)
Q_DECLARE_METATYPE(ns_Infinova_readXml::DeviceInfo *)
Q_DECLARE_METATYPE(ns_Infinova_readXml::CameraInfo *)
#endif // READXML_H
