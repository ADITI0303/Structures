#include<stdio.h>
#include<stdlib.h>

typedef struct _linkedlist
{
    int data;
    struct _linkedlist *next;
}STACKITEM;

STACKITEM* head = NULL;

void push(int);

STACKITEM* pop();
void printPop(STACKITEM*);


int main()
{
    push(3);
    printf("Value is %d\n", head->data);
    push(4);
    printf("Value is %d\n", head->data);
    printf("Value is %d\n", head->next->data);
    STACKITEM* Node = pop();
    printPop(Node);
    Node = pop();
    printPop(Node);
    Node = pop();
    printPop(Node);
    return 0;
}

void push(int newData)
{
    STACKITEM* Node = (STACKITEM*)malloc(sizeof(STACKITEM));
    Node->data = newData;
    if(head == NULL)
    {
        head = Node;
        head->next = NULL;
    }
    else
    {
        Node->next = head;
        head = Node;
    }
}


STACKITEM* pop()
{
    if(head == NULL)
    {
        printf("Invalid Operation\n");
        return;
    }
    STACKITEM* temp;
    temp = head;
    head = temp->next;
    temp->next = NULL;
    return temp;
}

void printPop(STACKITEM* Node)
{
    if(Node!=NULL)
    {
        printf("The value at the node is: %d\n", Node->data);
    }
}
