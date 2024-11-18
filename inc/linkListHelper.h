// linkListHelper.h

#ifndef LINKLIST_H
#define LINKLIST_H

// struct types
struct node {
    int data;
    struct node * link;
};

// FUNC Declarations
void testLinkedList();
struct node * createNode();
void deleteSingleList( struct node * head);

#endif