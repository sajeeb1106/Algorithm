#include <stdio.h>

int iterativeLinearMaxMin(int arr[], int size, int *max, int *min)
{
    *max = arr[0];
    *min = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > *max)
        {
            *max = arr[i];
        }
        if (arr[i] < *min)
        {
            *min = arr[i];
        }
    }
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

    printf("\n");

    int max, min;

    iterativeLinearMaxMin(arr, size, &max, &min);

    printf("\nMaximum element: %d\n", max);
    printf("Minimum element: %d\n", min);
}