#include<stdio.h>

int recursiveBinarySearch(int arr[], int left, int right, int search)
{
    if(left > right)
    {
        return -1; 
    }

    int mid = (left + right) / 2;

    if(arr[mid] == search)
    {
        return mid; 
    }
    if(arr[mid] < search)
    {
        return recursiveBinarySearch(arr, mid + 1, right, search);
    }
    else
    {
        return recursiveBinarySearch(arr, left, mid - 1, search);
    }
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

    // recursive binary search
    int rresult = recursiveBinarySearch(arr, 0, size - 1, search);

    printf("\nRecursive Binary Search:\n");
    if(rresult != -1)
    {
        printf("Element found at index %d\n", rresult);
    }
    else
    {
        printf("Element not found in the array\n");
    }   
}