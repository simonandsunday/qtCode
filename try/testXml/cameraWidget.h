#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H

#include <QWidget>
#include"readXml.h"
namespace Ui {
class cameraWidget;
}

class cameraWidget : public QWidget
{
    Q_OBJECT

public:
    explicit cameraWidget(QWidget *parent = 0);
    ~cameraWidget();
    void setData(ns_Infinova_readXml::CameraInfo *data);
private:
    Ui::cameraWidget *ui;
};

#endif // CAMERAWIDGET_H
