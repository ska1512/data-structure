#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *list; // Global list

// Init list
void Init()
{
    // if list is already initialized or not defined
    if (list == NULL)
    {
        return;
    }
    // if list is existed
    else
    {
        Node *currentNode;
        currentNode = list;

        // free all nodes
        while (currentNode != NULL)
        {
            list = currentNode->next;
            free(currentNode);
            currentNode = list;
        }
    }
}

// Add in list
void Add(int key)
{
    // create new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = key;
    newNode->next = NULL;

    Node *currentNode = list;

    // if list is empty
    if (list == NULL)
    {
        list = newNode;
        return;
    }

    // if list is not empty, get tail node
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    // set newNode to tail node of list
    currentNode->next = newNode;
}

// Remove element in position
void Remove(int key)
{
    Node *currentNode = list->next;
    Node *previousNode = list;

    // if list is already initialized or undefined
    if (list == NULL)
    {
        return;
    }

    // if remove first node
    if (key == 1)
    {
        Node *currentNode = list;
        list = list->next;
        free(currentNode);
        return;
    }

    else
    {
        for (int i = 0; i < key - 2; i++)
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        if (currentNode == NULL)
        {
            return;
        }
        previousNode->next = currentNode->next;
        free(currentNode);
        return;
    }
}

// show all elements
void Display()
{
    Node *currentNode = list;
    while (currentNode != NULL)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main()
{
    // data to insert
    int data = 0;
    // position to insert
    int key = 0;

    // Init list
    Init();

    printf("Enter 5 elements in array : ");

    // Add 5 elements in list
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &data);
        Add(data);
    }

    // show all elements
    printf("Stored element in array : ");
    Display();

    // get position to remove
    printf("Enter poss. of element to delete : ");
    scanf("%d", &data);
    Remove(data);

    // show all elements after deletion
    printf("After deletion elements in array : ");
    Display();

    return 0;
}