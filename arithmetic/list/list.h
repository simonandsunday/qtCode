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
    tagNode *createRandList(int len);
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
    void print(tagNode *head);
};

}

#endif // LIST_H
