#include<stdio.h>

int RecursiveLinearSearch(int arr[], int size, int search, int index)
{
    if (index>=size)
    {
        return -1;
    }
    if(arr[index] == search)
    {
        return index;
    }
    return RecursiveLinearSearch(arr, size, search, index+1);
}

int main() 
{
    int size, i, search;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    for(i=0; i<size; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("\n");
    printf("Enter the value to search: ");
    scanf("%d", &search);

    int rresult = RecursiveLinearSearch(arr, size, search, 0);
    if(rresult != -1)
    {
        printf("\nElements found at index: %d\n", rresult);
    }
    else
    {
        printf("\nElement not found in the array.\n");
    }
}