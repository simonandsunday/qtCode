#include "MainWindow.h"
#include <QApplication>
#include"testqstringList.h"
#include"testProperty.h"
#include<QVariant>
#include<QDebug>
#include<QMetaProperty>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    testProperty entity;
    entity.setProperty("testdata","dafdsf");
    entity.setProperty("testdata1","dafdsf1");
    entity.setProperty("testdata2","dafdsf2");
    entity.setProperty("objectName","test");
    QVariant data=entity.property("testdata");
    qDebug()<< data.toString();
    //qDebug()<< entity.gettestdata1();
    QObject *object=(QObject*)&entity;
    const QMetaObject *metaObject=object->metaObject();
    int count=metaObject->propertyCount();
    qDebug()<<count;
    for(int i=0;i<count;i++){
        QMetaProperty metaProperty=metaObject->property(i);
        const char * name=metaProperty.name();
        QVariant value=object->property(name);
        qDebug()<<name<<value.toString();
    }
    return a.exec();
}
