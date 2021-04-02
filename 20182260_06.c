#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct Stack
{
    int data;
    struct Stack *link;
} Stack;

Stack *top; // Global stack

bool IsStackEmpty()
{
    if (top == NULL)
    {
        printf("Stack is empty!\n");
        return true;
    }
    return false;
}

void Push()
{
    while (1)
    {
        int pushNumber;
        char pushRepeatBoolean;

        printf("\nEnter element in stack:");
        scanf("%d", &pushNumber);

        Stack *newNode = (Stack *)malloc(sizeof(Stack));
        newNode->data = pushNumber;
        newNode->link = top;
        top = newNode;

        printf("\nPushed an element (Y/N)");
        scanf(" %c", &pushRepeatBoolean);

        if (pushRepeatBoolean == 'n' || pushRepeatBoolean == 'N')
        {
            break;
        }
        else if (pushRepeatBoolean == 'y' || pushRepeatBoolean == 'Y')
        {
            continue;
        }
    }
}

int Pop()
{
    if (!IsStackEmpty())
    {
        Stack *temp = top;
        int data = temp->data;
        top = temp->link;
        free(temp);
        return data;
    }
    else
    {
        // return error value
        return 1e9;
    }
}

void Display()
{
    if (!IsStackEmpty())
    {
        Stack *temp = top;
        printf("\n");
        while (temp)
        {
            printf("%d\n", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

int main()
{
    int number;
    int pushRepeat = 1;
    int deleteData;

    while (1)
    {
        char pushRepeatBoolean;

        printf("1 : push\n2 : pop\n3: display\n4: exit\nEnter element in stack: ");
        scanf("%d", &number);
        switch (number)
        {
        case 1:
            Push();
            break;
        case 2:
            deleteData = Pop();
            // if got error value
            if (deleteData != 1e9)
            {
                printf("\ndeleted data is : %d\n", deleteData);
            }
            printf("Pushed an element (Y/N)");
            scanf(" %c", &pushRepeatBoolean);
            if (pushRepeatBoolean == 'y' || pushRepeatBoolean == 'Y')
            {
                Push();
            }
            break;
        case 3:
            Display();
            printf("Pushed an element (Y/N)");
            scanf("%c", &pushRepeatBoolean);
            if (pushRepeatBoolean == 'y' || pushRepeatBoolean == 'Y')
            {
                Push();
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong selection.\n\n");
        }
    }
}