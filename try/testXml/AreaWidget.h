#ifndef AREAWIDGET_H
#define AREAWIDGET_H

#include <QWidget>
#include"readXml.h"
namespace Ui {
class AreaWidget;
}

class AreaWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AreaWidget(QWidget *parent = 0);
    ~AreaWidget();
    void setData(ns_Infinova_readXml::AreaInfo *item);
private:
    Ui::AreaWidget *ui;
};

#endif // AREAWIDGET_H
