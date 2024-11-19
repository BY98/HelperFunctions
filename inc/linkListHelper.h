// linkListHelper.h

#include <stdbool.h>

#ifndef LINKLIST_H
#define LINKLIST_H

// struct types
struct node {
    int data;
    struct node * link;
};

// FUNC Declarations
void testLinkedList();
void printList(struct node * head);
int countElements(struct node * head);
struct node * createNode(int data);
bool insertNode(struct node ** headPtr, struct node * ptr, int pos);
bool deleteNode( struct node ** headPtr, int pos);
void deleteSingleList( struct node ** head);

#endif