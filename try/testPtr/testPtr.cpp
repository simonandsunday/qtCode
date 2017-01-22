#include "testPtr.h"
#include<stdio.h>
#include<string>
#include<QDebug>
#include<auto_ptr.h>
#include<memory>
#include<tr1/memory>
#define qdebugex() qDebug()<<__func__<<__LINE__
namespace ns_testPrt{
testPtr::testPtr()
{

}

void testPtr::test_auto_ptr()
{
    test_auto_ptr_1();
    test_auto_ptr_2();
}

void testPtr::test_unique_ptr()
{

}

void testPtr::test_shared_ptr()
{
    //test_shared_ptr_1();
    std::tr1::shared_ptr<itemClass> ps=test_shared_ptr2();
    //ps->hello();
    m_list.append(ps);
    for(int i=0;i<m_list.size();i++){
        std::tr1::shared_ptr<itemClass> data=m_list.at(i);
        qdebugex()<<"i:"<<i;
        data->hello();
    }
    m_list.clear();
}

void testPtr::test_auto_ptr_1()
{
    std::auto_ptr<itemClass> ps (new itemClass(1));
    std::auto_ptr<itemClass> ps1 (new itemClass(2));
}

void testPtr::test_auto_ptr_2()
{
    std::auto_ptr<itemClass> ps (new itemClass(1));
    std::auto_ptr<itemClass> ps1=ps;
    ps1->hello();
    //ps->hello(); error
}

void testPtr::test_unique_ptr_1()
{

}

void testPtr::test_unique_ptr_2()
{

}

void testPtr::test_unique_ptr_3()
{

}

void testPtr::test_shared_ptr_1()
{
    std::tr1::shared_ptr<itemClass> ps (new itemClass(1));
    std::tr1::shared_ptr<itemClass> ps1=ps;
    ps1->hello();
    ps->hello();
}

std::tr1::shared_ptr<itemClass> testPtr::test_shared_ptr2()
{
    std::tr1::shared_ptr<itemClass> ps (new itemClass(1));
    m_list.append(ps);
    return ps;
}



itemClass::itemClass(int data):m_data(data)
{
    qdebugex()<<"new itemClass"<<data;
}

itemClass::~itemClass()
{
    qdebugex()<<"delete itemClass"<<m_data;

}

void itemClass::hello()
{
    qdebugex()<<"data:"<<m_data<<this;
}

}
