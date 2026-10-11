#include<stdio.h>

int main()
{
    int size, i, j, temp;

    printf("Enter number of elements: ");
    scanf("%d", &size);

    int arr[size];
    for(i=0; i<size; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    // Bubble Sort Logic...
    for (i=0; i<size-1; i++)
    {
        for(j=0; j<size-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\nSorted array is: ");
    for(i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
}