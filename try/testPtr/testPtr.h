#ifndef TESTPTR_H
#define TESTPTR_H
#include<stdio.h>
#include<string>
#include<tr1/memory>
#include<QList>
namespace ns_testPrt{
class itemClass{
public:
    itemClass(int data);
    ~itemClass();
    void hello();
private:
    int m_data;
    QList<std::tr1::shared_ptr<itemClass*> > m_test;
};
typedef struct __tagNode{
    int id;
    QList<std::tr1::shared_ptr<__tagNode> > nodeList;
}tagNode;
class testPtr
{
public:
    testPtr();
    void test_auto_ptr();
    void test_unique_ptr();
    void test_shared_ptr();
private:
    void test_auto_ptr_1();
    void test_auto_ptr_2();
    void test_unique_ptr_1();
    void test_unique_ptr_2();
    void test_unique_ptr_3();
    void test_shared_ptr_1();
    std::tr1::shared_ptr<itemClass> test_shared_ptr2();
   // QList<int> m_list;

    QList<std::tr1::shared_ptr<itemClass> > m_list;
};
}
#endif // TESTPTR_H
