#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;

}Node;

Node* createNode(int val)
{
    Node *newNode=calloc(1,sizeof(Node));
    newNode->next = NULL;
    newNode->data = val;
    return newNode;
}

Node* push(Node*top,int val)
{
    //make node
    Node* newNode = createNode(val);

    //put new node on the top
    newNode->next = top;

    //return the new top
    return newNode;
}

// top is Node ** because we passed in the address of the top so that we can edit the original
Node * pop(Node **top)
{
    // check if the stack is empty
    // We use *top because we have to dereference the address we passed in to get to the top node
    if((*top)== NULL)return -1;

     // if the stack is not empty we store the value of the top node
     int val = (*top)->data;

     //we make temp the node next to top
     Node *tmp = (*top)->next;

     //free the top
     free((*top));

     //now the top is the node next in line from the old top
     *top = tmp;

     //return value we popped
     return val;
}
void printStack(Node *top)
{
    while (top != NULL)
    {
        printf("%d\n", top->data);
        top = top->next;
    }
}

int topFunction(Node *top)
{
    // check if the stack is empty so we don't dereference null
    if (top == NULL)
        return -1;
    // if the stack is not empty then return the top value without altering it
    return top->data;
}
int main()
{
    // create the stack, we will use top instead of head so that it makes more sense in terms of a stack
    Node *top = NULL;

    // add values to the stack
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);

    // print the stack and note that the most recently added item should be at the top
    printStack(top);

    // remove elements from the stack while printing their value
    for (int i = 0; i < 4; i++)
    {
        // check if there are any values to pop before printing
        if (topFunction(top) != -1)
        {

            printf("The value we just popped is %d\n", pop(&top)); // notice that the values get popped starting from the top
            printStack(top);
        }else
            printf("There are no values in the stack\n");
    }

    return 0;
}
