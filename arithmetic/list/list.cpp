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
    if(head==NULL){
        return NULL;
    }
    tagNode *tHead=NULL;
    tagNode *max=head;
    while(max!=NULL){
        tagNode *curr=head;
        //find
        while(curr!=NULL){
            if(max->value<curr->value){
                max=curr;
            }else{
                //do nothing
            }
            curr=curr->next;
        }
        //add
        if(tHead==NULL){
            tHead=max;
        }else{
            tagNode *temp=tHead;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=max;
        }
        //remove
        if(head==max){
            tagNode *headTemp=head;
            head=head->next;
            headTemp->next=NULL;
        }else{
            tagNode *temp=head;
            while(temp->next!=max){
                temp=temp->next;
            }
            temp->next=max->next;
            max->next=NULL;
        }
        max=head;
    }

    return tHead;
}

tagNode *list::insertSort(tagNode *head)
{
    if(head==NULL){
        return head;
    }
    tagNode *tHead=NULL;
    while(head!=NULL){
        tagNode *curr=head;
        head=head->next;
        curr->next=NULL;
        //插入
        tagNode *tCurr=tHead;
        if(tCurr==NULL){
            tHead=curr;
        }else{
            if(tCurr->value<curr->value){
                tagNode *headTemp=tHead;
                tHead=curr;
                tHead->next=headTemp;
            }else{
                while(tCurr->next!=NULL){
                    if(tCurr->next->value>curr->value){
                        tCurr=tCurr->next;
                    }else{
                        break;
                    }
                }
                tagNode *temp=tCurr->next;
                tCurr->next=curr;
                curr->next=temp;
            }
        }
    }
    return tHead;
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

void list::myPrint(tagNode *head)
{
    qDebug()<<__func__<<__LINE__<<"myPrint";
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

void list::printLots(tagNode *lHead, tagNode *pHead)
{
    if(lHead==NULL){
        return;
    }
    if(pHead==NULL){
        return;
    }
    //找pHead value(代表lHead位置) 中
    tagNode *curr=pHead;
    int positon=0;
    tagNode *lcurr=lHead;
    while (curr!=NULL) {
        int value=curr->value;
        while(lcurr!=NULL&&value!=positon){
            positon++;
            lcurr=lcurr->next;
        }
        if(lcurr==NULL){
            break;
        }
        qdebugEx()<<lcurr->value;
        curr=curr->next;
    }
}

tagNode *list::intersect(tagNode *lHead, tagNode *pHead)
{
    tagNode *head=NULL;
    if(lHead==NULL){
        return pHead;
    }
    if(pHead==NULL){
        return lHead;
    }

    tagNode *lcurr=lHead;
    tagNode *pcurr=pHead;
    if(pcurr->value>lcurr->value){
        head=pHead;
        pcurr=pcurr->next;
    }else if(pcurr->value==lcurr->value){
        head=lHead;
        lcurr=lcurr->next;
        pcurr=pcurr->next;
    }else{
        head=lHead;
        lcurr=lcurr->next;
    }
    tagNode *headCurr=head;
    while(lcurr!=NULL&&pcurr!=NULL){
        if(lcurr->value>pcurr->value){
            headCurr->next=lcurr;
            lcurr=lcurr->next;
        }else if(lcurr->value==pcurr->value){
            headCurr->next=lcurr;
            lcurr=lcurr->next;
            pcurr=pcurr->next;
        }else{
            headCurr->next=pcurr;
            pcurr=pcurr->next;
        }
        headCurr=headCurr->next;
    }
    if(lcurr==NULL&&headCurr!=NULL){
        headCurr->next=pcurr;
    }else if(pcurr==NULL&&headCurr!=NULL){
        headCurr->next=lcurr;
    }
    return head;
}

tagNode *list::Union(tagNode *lHead, tagNode *pHead)
{

}

tagNode *list::addPloy(tagNode *lhead, tagNode *phead)
{
    if(lhead==NULL){
        return phead;
    }
    if(phead==NULL){
        return lhead;
    }
    tagNode *outHead=NULL;
    tagNode *pcurr=phead;
    tagNode *lcurr=lhead;
    tagNode *ocurr=NULL;
    if(pcurr->num>lcurr->num){
        ocurr=pcurr;
        pcurr=pcurr->next;
    }else if(pcurr->num<lcurr->num){
        ocurr=lcurr;
        lcurr=lcurr->next;
    }else{
        tagNode *item=new tagNode;
        item->next=NULL;
        item->value=lcurr->value+pcurr->value;
        item->num=0;
        ocurr=item;

        lcurr=lcurr->next;
        pcurr=pcurr->next;
    }
    outHead=ocurr;
    while(pcurr!=NULL&&lcurr!=NULL){
        if(pcurr->num>lcurr->num){
            ocurr->next=pcurr;
            pcurr=pcurr->next;
            ocurr=ocurr->next;
        }else if(pcurr->num<lcurr->num){
            ocurr->next=pcurr;
            lcurr=lcurr->next;
            ocurr=ocurr->next;
        }else{
            int num=lcurr->num;
            int value=lcurr->value+pcurr->value;
            tagNode *item=new tagNode;
            item->num=num;
            item->value=value;
            item->next=NULL;
            ocurr->next=item;
            ocurr=ocurr->next;
            lcurr=lcurr->next;
            pcurr=pcurr->next;
        }
    }
    if(pcurr==NULL){
        ocurr->next=lcurr;
    }else{
        ocurr->next=pcurr;
    }
    return outHead;
}

tagNode *list::mutiPloy(tagNode *lhead, tagNode *phead)
{
    if(lhead==NULL){
        return phead;
    }
    if(phead==NULL){
        return lhead;
    }
    tagNode *outhead=NULL;
    tagNode *lcurr=lhead;
    tagNode *pcurr=phead;
    tagNode *ocurr=NULL;
    while(lcurr!=NULL){
        while(pcurr!=NULL){
            int num=pcurr->num+lcurr->num;
            int value=pcurr->value*lcurr->value;
            //插入
            if(ocurr==NULL){
                tagNode *item=new tagNode;
                item->value=value;
                item->num=num;
                item->next=NULL;
                ocurr=item;
                outhead=item;
            }else{
                if(ocurr->num<num){
                    tagNode *item=new tagNode;
                    item->value=value;
                    item->num=num;
                    item->next=ocurr;
                    outhead=item;
                }else if(ocurr->num==num){
                    ocurr->value=ocurr->value+value;
                }else{
                    while(ocurr->next!=NULL) {
                        if(ocurr->next->num<=num){
                            break;
                        }else{
                            ocurr=ocurr->next;
                        }
                    }
                    if(ocurr->next==NULL){
                        tagNode *item=new tagNode;
                        item->value=value;
                        item->num=num;
                        item->next=NULL;
                        ocurr->next=item;
                    }else {
                        if(ocurr->next->num==num){
                            ocurr->next->value=ocurr->next->value+value;
                        }else{
                            tagNode *item=new tagNode;
                            item->value=value;
                            item->num=num;
                            tagNode *curr=ocurr->next;
                            ocurr->next=item;
                            item->next=curr;
                        }
                    }
                }
            }
        }
        lcurr=lcurr->next;
        pcurr=phead;
    }
}

tagNode *list::mutiPloy2(tagNode *lhead, tagNode *phead)
{
    if(lhead==NULL){
        return phead;
    }
    if(phead==NULL){
        return lhead;
    }
    tagNode *lcurr=lhead;
    tagNode *pcurr=phead;
    tagNode *outhead;
    tagNode *outcurr=NULL;
    while(lcurr!=NULL){
        while(pcurr!=NULL){
            int num=pcurr->num+lcurr->num;
            int value=pcurr->value*lcurr->value;
            tagNode *item=new tagNode;
            item->next=NULL;
            item->num=num;
            item->value=value;
            if(outcurr==NULL){
                outcurr=item;
                outhead=item;
            }else{
                outcurr->next=item;
            }
            pcurr=pcurr->next;
        }
        lcurr=lcurr->next;
        pcurr=phead;
    }
    //合并outhead;
}

int list::pow(int x, int n)
{
    if(n==0){
        return 1;
    }
    if(n==1){
        return x;
    }
    if(isEven(n)){
        return pow(x*x,n/2)*2;
    }else{
        return pow(x*x,n/2);
    }
}

bool list::isEven(int n)
{

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
   //testInsert();
   //testmyPrint();
   // testmyPrintLots();
    //testIntersect();
    testAddPloy();
}

void testList::testReverse()
{
    qdebugStart();
    tagNode *head=createRandList(10);
    list listEntity;
    listEntity.myPrint(head);
    head=listEntity.reverse(head);
    listEntity.myPrint(head);
    listEntity.destroyList(head);
    qdebugEnd();
}

void testList::testSelectSort()
{
    qdebugStart();
    tagNode *head=createRandList(10);
    list listEntity;
    listEntity.myPrint(head);
    head=listEntity.selectSort(head);
    listEntity.myPrint(head);
    listEntity.destroyList(head);
    qdebugEnd();
}

void testList::testInsertSort()
{
    qdebugStart();
    tagNode *head=createRandList(10);
    list listEntity;
    listEntity.myPrint(head);
    head=listEntity.insertSort(head);
    listEntity.myPrint(head);
    listEntity.destroyList(head);
    qdebugEnd();
}

void testList::testBubbleSort()
{
    qdebugStart();
    tagNode *head=createRandList(10);
    list listEntity;
    listEntity.myPrint(head);
    head=listEntity.bubbleSort(head);
    listEntity.myPrint(head);
    listEntity.destroyList(head);
    qdebugEnd();
}

void testList::testSortInsert()
{
    qdebugStart();
    tagNode *head=createRandList(10);
    list listEntity;
    listEntity.myPrint(head);
    head=listEntity.bubbleSort(head);
    listEntity.myPrint(head);
    tagNode *node=new tagNode;
    node->value=10;
    listEntity.sortInsert(head,node);
    listEntity.myPrint(head);
    listEntity.destroyList(head);
    qdebugEnd();
}

void testList::testDel()
{
    qdebugStart();
    tagNode *head=createRandList(10);
    list listEntity;
    listEntity.myPrint(head);
    head=listEntity.del(head,6334);
    listEntity.myPrint(head);
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
    listEntity.myPrint(head);
    tagNode *node=new tagNode;
    node->value=10;
    node->next=NULL;
    listEntity.insert(head,node);
    listEntity.myPrint(head);
    listEntity.destroyList(head);
    qdebugEnd();
}

void testList::testPrint()
{
    qdebugStart();
    tagNode *head=createRandList(10);
    list listEntity;
    listEntity.myPrint(head);
    listEntity.destroyList(head);
    qdebugEnd();
}

void testList::testPrintLots()
{
    qdebugStart();
    tagNode *lhead=createRandList(10);
    list listEntity;
    listEntity.myPrint(lhead);
    int a[]={1,3,5,8};
    tagNode *pHead=createRandList(4,a);
    lhead=listEntity.selectSort(lhead);
    listEntity.myPrint(lhead);
    listEntity.printLots(lhead,pHead);
    listEntity.destroyList(lhead);
    listEntity.destroyList(pHead);
    qdebugEnd();
}

void testList::testIntersect()
{
    qdebugStart();
    tagNode *lhead=createRandList(10);
    list listEntity;
    listEntity.myPrint(lhead);
    int a[]={1,3,5,8,29358,26962,26500,29359};
    tagNode *pHead=createRandList(8);
    pHead=listEntity.insertSort(pHead);
    lhead=listEntity.insertSort(lhead);
    tagNode *head=listEntity.intersect(lhead,pHead);
    listEntity.myPrint(head);
    qdebugEnd();
}

void testList::testAddPloy()
{
    qdebugStart();
    tagNode *lhead=createRandList(5);
    tagNode *phead=createRandList(8);
    list listEntity;
    //lhead=listEntity.insertSort(lhead);
    //phead=listEntity.insertSort(phead);
    listEntity.myPrint(lhead);
    listEntity.myPrint(phead);
    tagNode *outHead=listEntity.addPloy(lhead,phead);
    listEntity.myPrint(outHead);
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

tagNode *testList::createRandList(int len, int a[])
{
    tagNode *head=NULL;
    tagNode *curr=NULL;
    for(int i=0;i<len;i++){
        tagNode *item=new tagNode;
        item->value=a[i];
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
