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
        printf("%d", temp->data);
        temp = temp->next;
        temp == NULL ? printf("") : printf("-->");
    }
    printf("\n----------------------------------------\n");
}

// Avoided because of some redundent code
// void reverseList(struct Node **list)
// {
//     if ((*list) == NULL || (*list)->next == NULL)
//     {
//         return;
//     }

//     struct Node *previous = NULL, *current = (*list), *next = current->next, *temp = NULL;
//     while (next != NULL)
//     {
//         current->next = previous;
//         previous = current;
//         temp = next->next;
//         next->next = current;
//         current = next;
//         next = temp;
//     }
//     (*list) = current;
//     return;
// }

void reverseList(struct Node **list)
{
    struct Node *pre = NULL, *current = (*list);
    while (current != NULL)
    {
        struct Node *next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    *list = pre;
}

int main()
{
    struct Node *head = NULL;
    struct Node *tail = NULL;

    int i = 1;

    for (i = 1; i < 1; i++)
    {
        createList(&head, &tail, i);
    }

    printList(head);
    reverseList(&head);
    printList(head);

    return 0;
}