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
    // if list is already initialized or undefined
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

// Insert new value in list
void AddIn(int data, int key)
{
    Node *currentNode = list;

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    // if list is already initialized or undefined
    if (list == NULL)
    {
        list = newNode;
    }
    else
    {
        // Add new node on position
        for (int i = 0; i < key - 2; i++)
        {
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
}

// show all nodes
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

    // get position to insert
    printf("Enter position for enter element : ");
    scanf("%d", &key);

    // get value to insert
    printf("Enter new element : ");
    scanf("%d", &data);
    AddIn(data, key);

    // show all elements after insertion
    printf("Stored data in array : ");
    Display();

    return 0;
}