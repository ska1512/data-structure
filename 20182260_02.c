#include <stdio.h>

int main()
{
    int num = 5;
    int array[50], index;

    // insert 5 numbers into array
    printf("Enter element in array : ");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &array[i]);
    }

    // show all elements
    printf("Stored element in array : ");
    for (int i = 0; i < num; i++)
    {
        printf("%d ", array[i]);
    }

    // get position of deletion
    printf("\nEnter poss. of element to delete : ");
    scanf("%d", &index);

    // order for deletion
    for (int i = index - 1; i < num; i++)
    {
        array[i] = array[i + 1];
    }

    // show all elements after deletion
    printf("After deletion elements in array : ");
    for (int i = 0; i < num - 1; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}