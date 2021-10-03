#include<stdio.h>
#include<stdlib.h>

typedef struct _listitem
{
    struct _listitem* next;
    struct _listitem* prev;
    int data;
}QUEUEITEM;

typedef struct
{
    QUEUEITEM* first;
    QUEUEITEM* last;
}QUEUEHDR;

void enqueue(QUEUEHDR*,QUEUEITEM*);
QUEUEITEM* dequeue(QUEUEHDR*);
int queueLength(QUEUEHDR*);
QUEUEITEM* removeAt(QUEUEHDR*, int);
QUEUEITEM* addAfter(QUEUEHDR*, int, QUEUEITEM*);
QUEUEITEM* addBefore(QUEUEHDR*, int, QUEUEITEM*);

QUEUEHDR head;

void enqueue(QUEUEHDR* headNode, QUEUEITEM* queueItem)
{
    QUEUEITEM* temp = headNode->last;
    headNode->last = queueItem;
    temp->next = queueItem;
    queueItem->prev = temp;
    queueItem->next = (QUEUEHDR*)&head;
}

QUEUEITEM* dequeue(QUEUEHDR* headNode)
{
    QUEUEITEM* temp = headNode->first;
    if(temp == (QUEUEITEM*)headNode)
    {
        temp = NULL;
    }
    else
    {
        headNode->first = temp->next;
        headNode->first->prev = (QUEUEITEM*)headNode;
    }
    return temp;
}

int queueLength(QUEUEHDR* headNode)
{
    QUEUEITEM* temp = headNode->first;
    if(temp == headNode)
    {
        return 0;
    }
    int length = 0;
    while(temp->next != headNode->first)
    {
        temp = temp->next;
        length++;
    }
    return length;
}

QUEUEITEM* removeAt(QUEUEHDR* headNode, int position)
{
    QUEUEITEM* temp = headNode->first;
    if(position < 1 || temp == headNode)
    {
        return NULL;
    }
    int i = 1;
    while(temp->next != headNode->first)
    {
        if(position == i)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->next = NULL;
            temp->prev = NULL;
            return temp;
        }
        temp = temp->next;
        i++;
    }
    return NULL;
}

QUEUEITEM* addAfter(QUEUEHDR* headNode, int position, QUEUEITEM* queueItem)
{
    QUEUEITEM* temp = (QUEUEITEM*)headNode->first;
    if(position < 1)
    {
        return NULL;
    }
    int i=1;
    while(temp->next != headNode->first)
    {
        if(position == i)
        {
            queueItem->next = temp->next;
            temp->next = queueItem;
            queueItem->next->prev = queueItem;
            queueItem->prev = temp;
            return temp;
        }
        temp = temp->next;
        i++;
    }
    printf("No node exists.\n");
    return NULL;
}

QUEUEITEM* addBefore(QUEUEHDR* headNode, int position, QUEUEITEM* queueItem)
{
    QUEUEITEM* temp = (QUEUEITEM*)headNode->first;
    if(position < 1)
    {
        return NULL;
    }
    int i=1;
    while(temp->next != headNode->first)
    {
        if(position == i)
        {
            queueItem->prev = temp->prev;
            temp->prev->next = queueItem;
            temp->prev = queueItem;
            queueItem->next = temp;
            return temp;
        }
        temp = temp->next;
        i++;
    }
    return NULL;
}

int main()
{
    head.first = (QUEUEITEM*)(&head);
    head.last = (QUEUEITEM*)(&head);
    QUEUEITEM* item = (QUEUEITEM*)malloc(sizeof(QUEUEITEM));
    item->data = 3;
    item->next = item->prev = NULL;
    enqueue(&head, item);
//    item = dequeue(&head);
//    if(item != NULL)
//    {
//        printf("Value is %d\n", item->data);
//    }
//    item = dequeue(&head);
//    if(item != NULL)
//    {
//        printf("Value is %d\n", item->data);
//    }
//    else
//    {
//        printf("Nothing!\n");
//    }
    int n = queueLength(&head);
    printf("Length of queue is: %d\n", n);
    item = removeAt(&head, 1);
    if(item != NULL)
    {
        printf("Value removed is: %d\n", item->data);
    }
    item->data = 2;
    item->next = item->prev = NULL;
    item = addAfter(&head, 1, item);
    if(item!=NULL)
    {
        printf("%d", item->data);
    }
    return 0;
}
