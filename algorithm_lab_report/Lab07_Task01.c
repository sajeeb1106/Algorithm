#include<stdio.h>
void merge(int arr[], int low, int mid, int high)
{
    int i=low, j=mid+1, k=0;
    int temp[high - low + 1];

    while(i<=mid && j<=high)
    {
        if(arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while(i<=mid)
    {
        temp[k++] = arr[i++];
    }

    while(j<=high)
    {
        temp[k++] = arr[j++];
    }

    for(i=low, k=0; i<=high; i++, k++)
    {
        arr[i] = temp[k];
    }
}

void mergesort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int i, size;
    printf("Enter the number of students: ");
    scanf("%d", &size);

    int arr[size];
    printf("\n");
    for(i = 0; i < size; i++)
    {
        printf("Enter the marks of student %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, size - 1);

    printf("\nSorted Marks (Ascending):\n");
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}