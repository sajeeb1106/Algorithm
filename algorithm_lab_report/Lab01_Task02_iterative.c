#include<stdio.h>

int iterativeLinearSearch(int arr[], int size, int search)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == search)
        {
            printf("Element found at index %d\n", i);
            count++;
        }
    }
    return count;
}

int main()
{
    int size, i, search;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    for (i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the element to search: ");
    scanf("%d", &search);

    int iresult = iterativeLinearSearch(arr, size, search);

    printf("\nIterative Search Result: %d\n", iresult);
}