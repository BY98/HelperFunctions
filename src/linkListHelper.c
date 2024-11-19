#include <stdio.h>
#include <stdlib.h>
#include <linkListHelper.h>

/**
 * @brief Counts the number of elements in the linked list.
 * 
 * This function iterates through the entire linked list, counts the number of nodes,
 * and returns the total count. If the list is empty, it prints an error message.
 *
 * @param head Pointer to the head of the linked list.
 * @return The number of elements in the list.
 */
int countElements(struct node * head)
{
    int elements = 0;

    if (head == NULL)
    {
        printf("ERROR: NULL PTR");
        return 0;
    }

    struct node * ptr = head;
    while ( ptr != NULL)
    {
        ptr = ptr->link;
        elements++;
    }

    return elements;

}

/**
 * @brief Prints the elements of the linked list.
 * 
 * This function prints the elements of the linked list along with the total number
 * of elements. If the list is empty, it prints an error message.
 *
 * @param head Pointer to the head of the linked list.
 */
void printList(struct node * head)
{
    if (head == NULL)
    {
        printf("ERROR: NULL PTR");
        return;
    }
    
    struct node * ptr = head;
    printf("The number of elements is : %d \n The elements are: ", countElements(head));

    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->link;
    }

    printf("\n");

}

/**
 * @brief Inserts a new node at a specified position in the linked list.
 * 
 * This function inserts a new node into the linked list at a specified position.
 * If the position is invalid, it prints an error message and returns false.
 *
 * @param headPtr Pointer to the head of the linked list.
 * @param newNode Pointer to the node to be inserted.
 * @param pos Position where the new node should be inserted.
 * @return True if insertion is successful, false otherwise.
 */
bool insertNode(struct node ** headPtr, struct node * newNode, int pos)
{
    
    int currentPos = 0;
    int numberElements = countElements(*headPtr);

    if (*headPtr == NULL || newNode == NULL)
    {
        printf("ERROR: NULL PTR ");
        return false;
    }   

    if (pos < 0 || pos > numberElements)
    {
        printf("ERROR: Invalid position %d. Valid positions are between 0 and %d.\n", pos, numberElements);
        return false;
    }


    if (pos == 0)
    {
        newNode->link = *headPtr;
        *headPtr = newNode;
        return true;
    }
    struct node * ptr = *headPtr;

    while (currentPos++ < (pos-1)  )
    {
        ptr = ptr->link;
    }

    newNode->link = ptr->link;
    ptr->link = newNode;

    return true;
}

/**
 * @brief Deletes the entire linked list.
 * 
 * This function frees all the nodes of the linked list, deallocating memory
 * for each node. It prints a message once the list is fully deleted.
 *
 * @param headPtr Pointer to the head of the linked list.
 */
void deleteSingleList( struct node ** headPtr)
{
    printf("\n\n");
    if (*headPtr == NULL)
    {
        printf("NULL PTR ERROR");
        return;
    }

    struct node * ptr = *headPtr;
    
    while (ptr != NULL)
    {
        ptr = ptr->link;
        free(*headPtr);
        *headPtr = ptr;
    }

    if (*headPtr == NULL)
    {
        printf("linkedList has been fully deleted ");
    }
}

/**
 * @brief Deletes a node at a specified position in the linked list.
 * 
 * This function removes a node from the linked list at a specified position.
 * It returns true if the deletion is successful, otherwise, it prints an error message.
 *
 * @param headPtr Pointer to the head of the linked list.
 * @param pos Position of the node to be deleted.
 * @return True if deletion is successful, false otherwise.
 */
bool deleteNode( struct node ** headPtr, int pos)
{
    int currentPos = 0;

    if (*headPtr == NULL || pos < 0 || pos >= countElements(*headPtr))
    {
        printf("ERROR: Invalid position %d. List is empty or position is out of bounds.\n", pos);
        return false;
    }

    struct node * ptr = *headPtr;
    struct node * deleteNode = *headPtr;

    if (pos == 0)
    {
        *headPtr = (*headPtr)->link;
        free(ptr);
        return true;    
    }


    while (currentPos++ < pos)
    {
        ptr = deleteNode;
        deleteNode = ptr->link;
        
    }

    ptr->link = deleteNode->link;
    free(deleteNode);

    return true;

}


/**
 * @brief Creates a new node with a specified data value.
 * 
 * This function allocates memory for a new node, assigns the given data value,
 * and sets the link of the node to NULL. If memory allocation fails, it prints an error.
 *
 * @param data The data value to be assigned to the new node.
 * @return Pointer to the newly created node, or NULL if allocation fails.
 */
struct node * createNode(int data)
{
    struct node * newNode = NULL;
    newNode = malloc(sizeof(struct node));
    if ( newNode == NULL)
    {
        printf(" ERROR: MALLOC FAILURE");
        return NULL;
    }
    newNode->data = data;
    newNode->link = NULL;

    return newNode;
    
}

/**
 * @brief Inserts a node at the end of the linked list.
 * 
 * This function inserts a new node with the specified data value at the end of
 * the linked list. If the head of the list is NULL, it prints an error message.
 *
 * @param head Pointer to the head of the linked list.
 * @param data The data value to be inserted into the new node.
 */
void insertNodeEnd(struct node * head, int data)
{
    if (head == NULL)
    {
        printf("ERROR: NULL PTR");
        return;
    }

    struct node * ptr;
    struct node * newNode;

    ptr = head;
    newNode = malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("ERROR: MALLOC FAILURE");
        return;
    }
    newNode->data = data;
    newNode->link = NULL;

    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }

    ptr->link = newNode;

}

/**
 * @brief Runs a series of tests to validate linked list functions.
 * 
 * This function tests various linked list operations such as inserting nodes at
 * different positions, deleting nodes, and printing the list to ensure the correct
 * behavior of the linked list functions.
 */
void testLinkedList()
{
    printf("\n");
    
    bool testResult = false;
    struct node * head;
    struct node * testNode;

    head = createNode(1);
    testNode = createNode(2);
    if (testNode == NULL)
    {
        return ;
    }
    /* Add node to head-only list */
    testResult = insertNode(&head, testNode, 1);
    if (testResult == false)
    {
        printf(" Adding node to head-only list failed ");
    }
    testNode = createNode(3);
    if (testNode == NULL)
    {
        return ;
    }
    /* Add node to end of list*/
    testResult = insertNode(&head, testNode, 2);
    if (testResult == false)
    {
        printf(" Adding node to end of list failed ");
    }
    testNode = createNode(-5);
    if (testNode == NULL)
    {
        return ;
    }
    /* Replace head nodes */
    testResult = insertNode( &head, testNode, 0);
    if (testResult == false)
    {
        printf(" Replacing head node failed ");
    }
    testNode = createNode(15);
    if (testNode == NULL)
    {
        return ;
    }
    /* Insert node inbetween nodes */
    testResult = insertNode( &head, testNode, 2);
    if (testResult == false)
    {
        printf(" Inserting node failed ");
    }
    printList(head);
    testResult = deleteNode(&head, 2);
    if (testResult == false)
    {
        printf(" Deleting node failed ");
    }
    printList(head);
    testResult = deleteNode(&head, 0);
    if (testResult == false)
    {
        printf(" Deleting head node failed ");
    }
    printList(head);
    deleteSingleList(&head);

    printf("\n\n");
    
}