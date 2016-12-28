#ifndef INFINOVAPAGE_H
#define INFINOVAPAGE_H

#include <QWidget>
#include<QTreeWidget>
#include"readXml.h"
namespace Ui {
class InfinovaPage;
}

class InfinovaPage : public QWidget
{
    Q_OBJECT

public:
    explicit InfinovaPage(QWidget *parent = 0);
    ~InfinovaPage();

    enum {
        areaInfo_type=1,
        deviceInfo_type,
        cameraInfo_type
    };
private slots:
    void on_toolButton_clicked();
private:
    void initTree(QMap<QString,ns_Infinova_readXml::AreaInfo *> AreaInfoMap);
    void initArea(ns_Infinova_readXml::AreaInfo *item,QTreeWidgetItem *parent);
    void initDevice(ns_Infinova_readXml::DeviceInfo *item,QTreeWidgetItem* parent);
    void initCamera(ns_Infinova_readXml::CameraInfo *item,QTreeWidgetItem* parent);

private:
    Ui::InfinovaPage *ui;
};

#endif // INFINOVAPAGE_H
