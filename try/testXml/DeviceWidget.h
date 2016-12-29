#ifndef DEVICEWIDGET_H
#define DEVICEWIDGET_H

#include <QWidget>
#include"readXml.h"
namespace Ui {
class DeviceWidget;
}

class DeviceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceWidget(QWidget *parent = 0);
    ~DeviceWidget();
    void setData(ns_Infinova_readXml::DeviceInfo *data);
private:
    Ui::DeviceWidget *ui;
};

#endif // DEVICEWIDGET_H
