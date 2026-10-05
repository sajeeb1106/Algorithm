#include<stdio.h>

int iterativeBinarySearch(int arr[], int size, int search)
{
    int left = 0;
    int right = size - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(arr[mid] == search)
        {
            return mid; 
        }
        else if(arr[mid] < search)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1; 
}

int main()
{
    int size, i, left, right, mid, search;

    printf("Enter the size of the array: ");
    scanf("%d", &size); 

    int arr[size];
    printf("\n");
    for(i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the element to search: ");
    scanf("%d", &search);

    // iterative binary search
    int iresult = iterativeBinarySearch(arr, size, search);

    printf("\nIterative Binary Search:\n");
    if(iresult != -1)
    {
        printf("Element found at index %d\n", iresult);
    }
    else
    {
        printf("Element not found in the array\n");
    }
}