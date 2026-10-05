#include<stdio.h>

int comparisons = 0;
int recursiveBinarySearch(int arr[], int left, int right, int search)
{
    if(left > right)
    {
        return -1;
    }

    int mid = (left + right) / 2;
    comparisons++;

    if(arr[mid] == search)
    {
        return mid;
    }
    comparisons++;

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
    int size, i, search;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    for(i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the element to search: ");
    scanf("%d", &search);

    printf("\n");
    int rresult = recursiveBinarySearch(arr, 0, size - 1, search);
    if(rresult != -1)
    {
        printf("Element found at index %d\n", rresult);
    }
    else
    {
        printf("Element not found in the array\n");
    }
    printf("Number of comparisons: %d\n", comparisons);
}