#include<stdio.h>

int IterativeLinearSearch(int arr[], int size, int search)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i] == search)
        {
            return i;
        }
    }
    return -1;
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

    int iresult = IterativeLinearSearch(arr, size, search);
    if(iresult != -1)
    {
        printf("\nElements found at index: %d\n", iresult);
    }
    else
    {
        printf("\nElement not found in the array.\n");
    }
}