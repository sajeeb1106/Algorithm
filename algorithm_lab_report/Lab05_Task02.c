#include<stdio.h>

int main()
{
    int size, i, j, min, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    printf("\n");
    for(i = 0; i < size; i++)
    {
        printf("Enter priority score %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Selection Sort Algorithm (Ascending Order)
    for(i = 0; i < size - 1; i++)
    {
        min = i;
        for(j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    printf("\nSorted Priority Scores: ");
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}