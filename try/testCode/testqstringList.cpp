#include "testqstringList.h"
#include<QStringList>
#include<QDebug>
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
