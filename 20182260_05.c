#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    struct Node *front;
    struct Node *rear;
} Queue;

Queue *queue; // Global queue

bool IsQueueEmpty()
{
    if (queue->front != NULL)
    {
        return false;
    }
    return true;
}

// get number of nodes
int GetNodesCount()
{
    if (IsQueueEmpty())
    {
        return 0;
    }
    Node *currentNode = queue->front;
    int nodeCount = 1;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
        nodeCount++;
    }
    return nodeCount;
}

void DisplayNodes()
{
    if (IsQueueEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }

    Node *currentNode = queue->front;
    printf("Items : %d  ", currentNode->data);
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
        printf("%d  ", currentNode->data);
    }
    printf("\n");
}

void Enqueue(int value)
{
    Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (IsQueueEmpty())
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Successfully Insert\n");
}

int Dequeue()
{
    int result = queue->front->data;
    Node *garbage = queue->front;
    queue->front = queue->front->next;
    free(garbage);
    return result;
}

int main()
{
    // allocate and init global queue
    queue = malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;

    // value for menu selection
    int number;
    // value for insertion
    int insertData;
    // value for deletion
    int deleteData;
    // value for limit max count of nodes
    int maxCount;

    printf("Enter a number of max nodes\n\n");
    scanf("%d", &maxCount);

    while (1)
    {
        printf("1. Insertion\n2. Deletion\n3. Display\n0. Exit\n\nSelect Option : ");
        scanf("%d", &number);
        switch (number)
        {
        case 1:
            if (GetNodesCount() < maxCount)
            {
                printf("Element : ");
                scanf("%d", &insertData);
                Enqueue(insertData);
                break;
            }
            else
            {
                printf("Queue is Full!\n");
                break;
            }
        case 2:
            if (IsQueueEmpty())
            {
                printf("Queue is empty!\n");
                break;
            }
            else
            {
                deleteData = Dequeue();
                printf("Deleted item : %d\n", deleteData);
                break;
            }
        case 3:
            DisplayNodes();
            break;
        case 0:
            exit(0);
        default:
            printf("Wrong selection\n\n");
        }
    }
}