#include<stdio.h>

int main()
{
    int size, i, j, temp;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    for(i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Insertion Sort Algorithm
    for(i = 1; i < size; i++)
    {
        temp = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    printf("Sorted array: ");
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}