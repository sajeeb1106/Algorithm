#include<stdio.h>

int recursiveLinearSearch(int arr[], int size, int search, int index)
{
    int count = 0;
    if (index >= size)
    {
        return 0;
    }
    if (arr[index] == search)
    {
        printf("Element found at index %d\n", index);
        count++;
    }
    return count + recursiveLinearSearch(arr, size, search, index + 1);
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

    int iresult = recursiveLinearSearch(arr, size, search, 0);

    printf("\nRecursive Search Result: %d\n", iresult);
}