#include <stdio.h>
#include <stdlib.h>
#include <linkListHelper.h>

void deleteSingleList( struct node * head)
{
    struct node *ptr = head;
    
    while (ptr != NULL)
    {
        ptr = ptr->link;
        free(head);
        head = ptr;
    }

    if (head == NULL)
    {
        printf("linkedList reset!!!!");
    }
}

struct node * createNode()
{
    struct node * newNode = NULL;
    newNode = malloc(sizeof(struct node));
    return newNode;
    
}

void insertNodeEnd(struct node * head, int data)
{
    struct node * ptr, * newNode;

    ptr = head;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;

    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }

    ptr->link = newNode;


}


void testLinkedList()
{
    struct node * head;

    head = createNode();
    insertNodeEnd (head, 1);
    deleteSingleList(head);

    
}