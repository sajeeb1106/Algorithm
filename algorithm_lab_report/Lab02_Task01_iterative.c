#include <stdio.h>

int comparisons = 0;
int iterativeBinarySearch(int arr[], int size, int search)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        comparisons++;

        if (arr[mid] == search)
        {
            return mid;
        }
        comparisons++;

        if (arr[mid] < search)
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

    int iresult = iterativeBinarySearch(arr, size, search);
    if (iresult != -1)
    {
        printf("\nElement found at index %d\n", iresult);
    }
    else
    {
        printf("\nElement not found in the array\n");
    }
    printf("Number of comparisons: %d\n", comparisons);
}