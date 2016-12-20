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
    return NULL;
}

tagNode *list::selectSort(tagNode *head)
{
    return NULL;
}

tagNode *list::insertSort(tagNode *head)
{
    return NULL;
}

tagNode *list::bubbleSort(tagNode *head)
{
    return NULL;
}

tagNode *list::sortInsert(tagNode *head, tagNode *node)
{
    return NULL;
}

tagNode *list::del(tagNode *head, int value)
{
    return NULL;
}

void list::destroyList(tagNode *head)
{

}

tagNode *list::insert(tagNode *head, tagNode *node)
{
    return NULL;
}

void list::print(tagNode *head)
{
    if(head==NULL){
        return ;
    }
    tagNode *curr=head;
    while(curr!=NULL&&curr->next!=NULL){
        qDebug()<<"value:"<<curr->value;
        curr=curr->next;
    }
    return;
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
    qdebugStart();
    tagNode *head=createRandList(10);
    list listEntity;
    listEntity.print(head);
    listEntity.destroyList(head);
    qdebugEnd();
}

tagNode *testList::createRandList(int len)
{
    tagNode *head=NULL;
    tagNode *curr=NULL;
    for(int i=0;i<len;i++){
        tagNode *item=new tagNode;
        item->value=rand();
        item->next=NULL;
        if(curr==NULL){
            curr=item;
            head=item;
            curr->next=NULL;
        }else{
            curr->next=item;
            curr=item;
        }
    }
    return head;
}
}
