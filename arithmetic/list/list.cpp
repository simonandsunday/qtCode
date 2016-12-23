#include "list.h"
#include<QDebug>
#define qdebugStart() qDebug()<<"start:"<<__func__<<__LINE__
#define qdebugEnd() qDebug()<<"end:"<<__func__<<__LINE__
#define qdebugEx() qDebug()<<__func__<<__LINE__
namespace ns_list{
list::list()
{

}

tagNode *list::reverse(tagNode *head)
{
    if(head==NULL){
        qdebugEx();
        return NULL;
    }
    tagNode *curr=head;
    tagNode *pre=NULL;
    while(curr!=NULL){
        tagNode *next=curr->next;
        curr->next=pre;
        if(next==NULL){
            break;
        }
        pre=curr;
        curr=next;
    }
    return curr;
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
    if(head==NULL){
        return NULL;
    }
    tagNode *curr=head;
    while(curr!=NULL){
        tagNode *next=curr->next;
        if(next==NULL){
            break;
        }
        if(next->value==value){
            curr->next=next->next;
            curr=next->next;
            delete next;
        }else{
            curr=next;
        }
    }
    if(head->value==value){
        curr=head->next;
        delete head;
        return curr;
    }
    return head;
}

void list::destroyList(tagNode *head)
{
    if(head==NULL){
        return;
    }
    tagNode *curr=head;

    while (curr!=NULL) {
        tagNode *next=curr->next;
        qdebugEx()<<"destroy node:"<<curr->num;
        delete curr;
        curr=NULL;
        curr=next;
    }
    head=NULL;
}

tagNode *list::insert(tagNode *head, tagNode *node)
{
    if(head==NULL){
        node->num=0;
        return node;
    }
    tagNode *curr=head;
    int num=1;
    while(curr->next!=NULL){
        curr=curr->next;
        num=num+1;
    }
    node->num=num;
    curr->next=node;
    return head;
}

void list::print(tagNode *head)
{
    qDebug()<<__func__<<__LINE__<<"print";
    if(head==NULL){
        qDebug()<<__func__<<__LINE__<<"head is null";
        return ;
    }
    tagNode *curr=head;
    while(curr!=NULL){
        qDebug()<<"value:"<<curr->value<<"num:"<<curr->num;
        curr=curr->next;
    }
    return;
}




testList::testList()
{
   //testReverse();

   //testSelectSort();
   //testInsertSort();
   //testBubbleSort();
   //testSortInsert();
   //testDel();
   //testDestroyList();
   testInsert();
   //testPrint();
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
    head=listEntity.del(head,6334);
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
    tagNode *node=new tagNode;
    node->value=10;
    node->next=NULL;
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
        item->num=i;
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
