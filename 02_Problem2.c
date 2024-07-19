/*
Problem Statement :- Write a program to remove duplicates from an unsorted linked list
For example -: Input: array =  [3,5,3,7,8,5,10]
Output: [3,5,7,8,10]
*/
#include <stdio.h>
#include <stdlib.h>

// Definition of the linked list node
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to remove duplicates from an unsorted linked list
void removeDuplicates(struct Node *head)
{
    struct Node *current = head, *prev = NULL, *temp;
    while (current != NULL && current->next != NULL)
    {
        prev = current;
        temp = current->next;
        while (temp != NULL)
        {
            if (current->data == temp->data)
            {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

// Function to print the linked list
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to convert an array to a linked list
struct Node *arrayToList(int arr[], int size)
{
    if (size == 0)
        return NULL;
    struct Node *head = createNode(arr[0]);
    struct Node *current = head;
    for (int i = 1; i < size; i++)
    {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:-\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct Node *head = arrayToList(arr, n);

    printf("Original list: ");
    printList(head);

    removeDuplicates(head);

    printf("List after removing duplicates: ");
    printList(head);

    return 0;
}