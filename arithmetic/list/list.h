#ifndef LIST_H
#define LIST_H

struct tagNode{
    int value;
    int num;
    tagNode *next;
};
namespace ns_list{

class testList{
public:
    testList();
private:
    void testReverse();
    void testSelectSort();
    void testInsertSort();
    void testBubbleSort();
    void testSortInsert();
    void testDel();
    void testDestroyList();
    void testInsert();
    void testPrint();
    void testPrintLots();
    void testIntersect();
    void testAddPloy();
    tagNode *createRandList(int len);
    tagNode *createRandList(int len,int a[]);
};
class list
{
public:
    list();
    tagNode *reverse(tagNode *head);
    tagNode *selectSort(tagNode *head);
    tagNode *insertSort(tagNode *head);
    tagNode *bubbleSort(tagNode *head);
    tagNode *sortInsert(tagNode *head,tagNode *node);

    tagNode *del(tagNode *head,int value);
    void destroyList(tagNode *head);
    tagNode *insert(tagNode *head,tagNode *node);
    void myPrint(tagNode *head);
    void printLots(tagNode *lHead,tagNode *pHead);
    tagNode *intersect(tagNode *lHead,tagNode *pHead);
    tagNode *Union(tagNode *lHead,tagNode *pHead);
    tagNode *addPloy(tagNode *lhead,tagNode *phead);
    tagNode *mutiPloy(tagNode *lhead,tagNode *phead);
    tagNode *mutiPloy2(tagNode *lhead,tagNode *phead);
    int pow(int x,int n);
    bool isEven(int n);
};

}

#endif // LIST_H
