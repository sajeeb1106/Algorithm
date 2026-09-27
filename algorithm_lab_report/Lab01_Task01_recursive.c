#include <stdio.h>

int recursiveLinearMaxMin(int arr[], int size, int *max, int *min, int index)
{
    if (index == size)
    {
        return 0;
    }
    if (arr[index] > *max)
    {
        *max = arr[index];
    }
    if (arr[index] < *min)
    {
        *min = arr[index];
    }

    recursiveLinearMaxMin(arr, size, max, min, index + 1);
}

int main()
{
    int size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    for (i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    int min = arr[0];
    recursiveLinearMaxMin(arr, size, &max, &min, 0);

    printf("\nMaximum element: %d\n", max);
    printf("Minimum element: %d\n", min);
}