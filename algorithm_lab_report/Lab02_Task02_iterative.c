#include <stdio.h>

int firstOccurrence(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;
    int first = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
        {
            first = mid;
            right = mid - 1;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return first;
}

int lastOccurrence(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;
    int last = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
        {
            last = mid;
            left = mid + 1;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return last;
}

int main()
{
    int size, i, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    for (i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the target element: ");
    scanf("%d", &target);

    int first = firstOccurrence(arr, size, target);
    int last = lastOccurrence(arr, size, target);

    if (first != -1)
    {
        int total = last - first + 1;

        printf("\nFirst Occurrence: %d\n", first);
        printf("Last Occurrence: %d\n", last);
        printf("Total Occurrences: %d\n", total);
    }
    else
    {
        printf("\nTarget not found in the array.\n");
        printf("Total Occurrences: 0\n");
    }
}