#include <stdio.h>

int main()
{
    int size, i, j, key;
    int evenCount = 0, k = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    int even[size];

    printf("\n");
    for(i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Store only even numbers
    for(i = 0; i < size; i++)
    {
        if(arr[i] % 2 == 0)
        {
            even[evenCount] = arr[i];
            evenCount++;
        }
    }

    // Insertion Sort for even numbers
    for(i = 1; i < evenCount; i++)
    {
        key = even[i];
        j = i - 1;

        while(j >= 0 && even[j] > key)
        {
            even[j + 1] = even[j];
            j--;
        }
        even[j + 1] = key;
    }

    // Replace even numbers in original positions
    for(i = 0; i < size; i++)
    {
        if(arr[i] % 2 == 0)
        {
            arr[i] = even[k];
            k++;
        }
    }

    printf("\nArray after sorting even numbers: ");
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}