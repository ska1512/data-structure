#include <stdio.h>

int main()
{
    int num = 5;
    int array[50], index, element;

    // insert 5 numbers into array
    printf("Enter 5 elements in array : ");
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

    // get position to insert
    printf("\nEnter position for enter element : ");
    scanf("%d", &index);
 
    // get new value
    printf("Enter new element : ");
    scanf("%d", &element);

    // make position for new value
    for (int i = num - 1; i >= index - 1; i--)
    {
        array[i + 1] = array[i];
    }

    // insert value
    array[index - 1] = element;

    // show all elements after insertion
    printf("Stored data in array : ");
    for (int i = 0; i <= num; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}