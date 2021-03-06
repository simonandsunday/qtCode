#include "testqstringList.h"
#include<QStringList>
#include<QDebug>
#include<QFile>
#define QStringLiteral QObject::tr
testqstringList::testqstringList()
{
    QStringList entity;
    entity<<"1"<<"2";
    qDebug()<<__func__<<__LINE__<<entity<<entity.join("");
}

void testqstringList::testEmtity()
{
    QStringList entity;
    //entity<<"1"<<"2";
    qDebug()<<__func__<<__LINE__<<entity<<entity.join("");
}

void testqstringList::testLength()
{
    QString data=QString("DeviceListForm\KBCPageManager.cpp doUploadMonitoryPointInfoPrior 1194 kbc:++++ here 118 1636 193048 3006 ");
    QStringList entity;
    for(int i=0;i<10000;i++){
        entity<<data;
        qDebug()<<data.length()<<"size:"<<entity.size()<<entity.size()*data.length();
    }
}

void testqstringList::testForeach()
{
    QHash<QString ,QString *> group;
    QString *item=new QString("4455");
    group.insert("11",item);
    foreach (QString *data,group) {
        qDebug()<<*data;
    }
    QHash<QString ,QString *>*pGroup=new QHash<QString,QString *>;
    pGroup->insert("445",item);
    foreach (QString *data, *pGroup) {
        qDebug()<<*data;
    }
}

void testqstringList::readfile()
{
    FILE *pfile=fopen("C:/Users/Administrator/Desktop/testlog.xml","r");
    char *pbuf;
    fseek(pfile,0,SEEK_END);
    int len=ftell(pfile);
    pbuf=new char[len+1];
    rewind(pfile);
    fread(pbuf,1,len,pfile);
    pbuf[len]=0;
    fclose(pfile);
}

void testqstringList::writeLocafile()
{
    QFile file("d:\\testfile.xml");
    if(!file.open(QIODevice::WriteOnly)){
        qDebug()<<"打开文件失败";
        return ;
    }
    QString xmlIn = QStringLiteral("<?xml version=\"1.0\" encoding=\"utf-8\" ?>\n \
                       <Param Factory=\"%1\" Device=\"KBC\" Func=\"SetCameraInfo\">\n \
                           <ConnectInfo IP=\"%2\" Slot=\"1\" Port=\"1\" Prior=\"255\"  ServerPort=\"40000\" ></ConnectInfo>\n \
                           <CameraInfo>\n%3\n</CameraInfo>\n \
                       </Param>");
    QTextStream  out(&file);
    out<<xmlIn;
    file.close();
}
