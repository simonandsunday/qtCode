#ifndef INFINOVAPAGE_H
#define INFINOVAPAGE_H

#include <QWidget>
#include<QTreeWidget>
#include"readXml.h"
#define Infinova_tree_Item_data_role (Qt::SizeHintRole+1000)
#define Infinova_tree_Item_type_role (Qt::SizeHintRole+1001)
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
    QTreeWidget *getTreeWidget();
private slots:
    void on_toolButton_clicked();
    void currentItemChangedSlot ( QTreeWidgetItem * current, QTreeWidgetItem * previous );
private:
    void initTree(QMap<QString,ns_Infinova_readXml::AreaInfo *> AreaInfoMap);
    void initArea(ns_Infinova_readXml::AreaInfo *item,QTreeWidgetItem *parent);
    void initDevice(ns_Infinova_readXml::DeviceInfo *item,QTreeWidgetItem* parent);
    void initCamera(ns_Infinova_readXml::CameraInfo *item,QTreeWidgetItem* parent);

private:
    Ui::InfinovaPage *ui;
};

#endif // INFINOVAPAGE_H
