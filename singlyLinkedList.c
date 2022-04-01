#include <stdio.h>
#include <stdlib.h>

// struct for a single linked list
typedef struct Node
{
    // the value stored in the node. This can be an int, a char, a string, etc
    int data;
    // The pointer to the next node in the list
    struct Node*next;
}Node;

// This function will create a node and initialize its data to the passed integer
Node *createNode(int);
Node *addToTail(Node *, int);
Node *addToFront(Node *, int);
void printList(Node *);
Node *deleteTail(Node *);
Node *deleteFront(Node *);
void freeList(Node *);



int main()
{
   // Here we create the linked list and set it equal to null to show that it is empty.
    Node *head = NULL;

    // let's add some values to the end of the list
    head = addToTail(head, 7);
    head = addToTail(head, 8);
    head = addToTail(head, 9);

    // Now let's add some values to the front of the list
    head = addToFront(head, 1);
    head = addToFront(head, 2);
    head = addToFront(head, 3);

    // Now we print the list
    printList(head);
    printf("******************************\n");

    head = deleteTail(head);
    printList(head);
    printf("******************************\n");

    head = deleteFront(head);
    printList(head);
    printf("******************************\n");

    freeList(head);

    return 0;
}

Node *createNode(int val)
{
    Node *newNode = calloc(1,sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
Node *addToFront(Node *head, int val)
{
    // if the list is empty, we return the new node
    if(head == NULL) return createNode(val);

    // if the list is not empty, then we just create a new node and stick it in front of the head
    Node *newNode = createNode(val);

    // Since it needs to go in front of the head we make the new node's next point to the head
    newNode->next = head;

    // and since we want the new node to be the first node, we make it the new head
    head = newNode;
    return head;

}
Node *addToTail(Node *head, int val)
{
     // if the list is empty or we reach the end of the list, we return the new node
     if(head == NULL) return createNode(val);

     // We use recursion to move to the end of the list.
     head->next = addToTail(head->next, val);

     return head;

}
void printList(Node *head)
{
    // if we reach the end of the list or if the list is empty, we just return
    if(head == NULL) return;

    // we print the current value
    printf("%d\n",head->data);

    // we use recursion to move down the list
    printList(head->next);
}

Node *deleteTail(Node *head)
{
    // if the tree is empty then there is nothing to remove
    if (head == NULL)
        return NULL;

    // Since getting to the node right before the tail requires us to use cur->next->next in the while loop, we have to first make sure that there are at least 2 nodes in the list
    if (head->next == NULL)
    {
        // if there is only 1 node in the list we can just remove it
        free(head);
        return NULL;
    }
    // when removing the tail of a linked list we want to traverse first to the node right before it
    // We can do that with the following while loop
    Node *cur = head;
    while (cur->next->next != NULL)
        cur = cur->next;

    // now cur is storing the node right before the tail
    // we can now remove the tail safely
    free(cur->next);
    // and set cur->next to null to show that it is the new tail
    cur->next = NULL;
    // return the head back to main
    return head;
}

Node *deleteFront(Node *head)
{
    //check to see if the list is empty
    if(head == NULL) return NULL;

    // Next we store whatever comes next in the list after head
    Node *tmp = head->next;

    // We free the head
    free(head);
    // We set head to be the node we had stored, since that will be the new head
    head = tmp;
    return head;
}
void freeList(Node *head)
{
     // if the list is empty or we reach the end of the list
    if(head == NULL) return;

     // we do the recursive call to move to the end of the list since you want to free from tail to head
    freeList(head->next);

    free(head);
}



