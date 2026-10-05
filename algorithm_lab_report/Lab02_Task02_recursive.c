#include <stdio.h>

int firstOccurrence(int arr[], int left, int right, int target)
{
    if (left > right)
    {
        return -1;
    }

    int mid = (left + right) / 2;
    if (arr[mid] == target)
    {
        int result = firstOccurrence(arr, left, mid - 1, target);

        if (result == -1)
        {
            return mid;
        }
        else
        {
            return result;
        }
    }
    else if (arr[mid] < target)
    {
        return firstOccurrence(arr, mid + 1, right, target);
    }
    else
    {
        return firstOccurrence(arr, left, mid - 1, target);
    }
}

int lastOccurrence(int arr[], int left, int right, int target)
{
    if (left > right)
    {
        return -1;
    }

    int mid = (left + right) / 2;
    if (arr[mid] == target)
    {
        int result = lastOccurrence(arr, mid + 1, right, target);

        if (result == -1)
        {
            return mid;
        }
        else
        {
            return result;
        }
    }
    else if (arr[mid] < target)
    {
        return lastOccurrence(arr, mid + 1, right, target);
    }
    else
    {
        return lastOccurrence(arr, left, mid - 1, target);
    }
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

    printf("Enter the target element: ");
    scanf("%d", &target);

    int first = firstOccurrence(arr, 0, size - 1, target);
    int last = lastOccurrence(arr, 0, size - 1, target);

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