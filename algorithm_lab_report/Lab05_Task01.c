#include<stdio.h>

int main()
{
    int size, i, j, max;
    float temp;

    printf("Enter the number of students: ");
    scanf("%d", &size);

    float arr[size];
    printf("\n");
    for(i = 0; i < size; i++)
    {
        printf("Enter CGPA of student %d: ", i + 1);
        scanf("%f", &arr[i]);
    }

    // Selection Sort Algorithm (Descending Order)
    for(i = 0; i < size - 1; i++)
    {
        max = i;
        for(j = i + 1; j < size; j++)
        {
            if(arr[j] > arr[max])
            {
                max = j;
            }
        }
        if(max != i)
        {
            temp = arr[max];
            for(j = max; j > i; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[i] = temp;
        }
    }

    printf("\nScholarship Ranking: ");
    for(i = 0; i < size; i++)
    {
        printf("%.2f ", arr[i]);
    }
}