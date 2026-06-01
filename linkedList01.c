#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void createList(struct Node **list, struct Node **tail, int data)
{
    // create a new node

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    // if list/ head is NULL, return newNode;

    if (*list == NULL)
    {
        *list = newNode;
        *tail = *list;
        return;
    }

    (*tail)->next = newNode;
    *tail = (*tail)->next;
    return;
}

void printList(struct Node *list)
{
    struct Node *temp = list;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

int main()
{

    struct Node *head = NULL;
    struct Node *tail = NULL;

    int i = 1;

    for (i = 1; i < 100; i ++){
        createList(&head, &tail, i);
    }

    printList(head);

    return 0;
}