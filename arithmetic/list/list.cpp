#include "list.h"
#include<QDebug>
#define qdebugStart() qDebug()<<"start:"<<__func__<<__LINE__
#define qdebugEnd() qDebug()<<"end:"<<__func__<<__LINE__
namespace ns_list{
list::list()
{

}

tagNode *list::reverse(tagNode *head)
{

}

tagNode *list::selectSort(tagNode *head)
{

}

tagNode *list::insertSort(tagNode *head)
{

}

tagNode *list::bubbleSort(tagNode *head)
{

}

tagNode *list::sortInsert(tagNode *head, tagNode *node)
{

}

tagNode *list::del(tagNode *head, int value)
{

}

void list::destroyList(tagNode *head)
{

}

tagNode *list::insert(tagNode *head, tagNode *node)
{

}

void list::print(tagNode *head)
{

}




testList::testList()
{
   testReverse();
   testSelectSort();
   testInsertSort();
   testBubbleSort();
   testSortInsert();
   testDel();
   testDestroyList();
   testInsert();
   testPrint();
}

void testList::testReverse()
{
    qdebugStart();
    tagNode *head=createRandList(10);
    list listEntity;
    listEntity.print(head);
    head=listEntity.reverse(head);
    listEntity.print(head);
    listEntity.destroyList(head);
    qdebugEnd();
}

void testList::testSelectSort()
{
    qdebugStart();
    tagNode *head=createRandList(10);
    list listEntity;
    listEntity.print(head);
    head=listEntity.selectSort(head);
    listEntity.print(head);
    listEntity.destroyList(head);
    qdebugEnd();
}

void testList::testInsertSort()
{
    qdebugStart();
    tagNode *head=createRandList(10);
    list listEntity;
    listEntity.print(head);
    head=listEntity.insertSort(head);
    listEntity.print(head);
    listEntity.destroyList(head);
    qdebugEnd();
}

void testList::testBubbleSort()
{
    qdebugStart();
    tagNode *head=createRandList(10);
    list listEntity;
    listEntity.print(head);
    head=listEntity.bubbleSort(head);
    listEntity.print(head);
    listEntity.destroyList(head);
    qdebugEnd();
}

void testList::testSortInsert()
{
    qdebugStart();
    tagNode *head=createRandList(10);
    list listEntity;
    listEntity.print(head);
    head=listEntity.bubbleSort(head);
    listEntity.print(head);
    tagNode *node=new tagNode;
    node->value=10;
    listEntity.sortInsert(head,node);
    listEntity.print(head);
    listEntity.destroyList(head);
    qdebugEnd();
}

void testList::testDel()
{
    qdebugStart();
    tagNode *head=createRandList(10);
    list listEntity;
    listEntity.print(head);
    head=listEntity.del(head,10);
    listEntity.print(head);
    listEntity.destroyList(head);
    qdebugEnd();
}

void testList::testDestroyList()
{
    qdebugStart();
    tagNode *head=createRandList(10);
    list listEntity;
    listEntity.destroyList(head);
    qdebugEnd();
}

void testList::testInsert()
{
    qdebugStart();
    tagNode *head=createRandList(10);
    list listEntity;
    listEntity.print(head);
    head=listEntity.bubbleSort(head);
    listEntity.print(head);
    tagNode *node=new tagNode;
    node->value=10;
    listEntity.insert(head,node);
    listEntity.print(head);
    listEntity.destroyList(head);
    qdebugEnd();
}

void testList::testPrint()
{

}

tagNode *testList::createRandList(int len)
{

}
}
