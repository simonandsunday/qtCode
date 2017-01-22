#ifndef TESTPROPERTY_H
#define TESTPROPERTY_H
#include<QObject>

class testProperty:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString test)
public:
    testProperty();


    QString F();
    void setF(QString data);
private:
    //QString testdata1;
};



#endif // TESTPROPERTY_H
