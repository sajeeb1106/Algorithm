#include<stdio.h>

int main()
{
    int size, i, j, k, temp;
    printf("Enter number of students: ");
    scanf("%d", &size);

    char id[size][20];
    int score[size];

    for(i=0; i<size; i++)
    {
        printf("\nEnter Student ID %d: ", i+1);
        scanf("%s", id[i]);

        printf("Enter exam score: ");
        scanf("%d", &score[i]);
    }

    // Bubble Sort Logic (Descending Order)
    for(i=0; i<size-1; i++)
    {
        for(j=0; j<size-i-1; j++)
        {
            if(score[j] < score[j+1])
            {
                temp = score[j];
                score[j] = score[j+1];
                score[j+1] = temp;

                char tempID[20];
                for(k=0; k<20; k++)
                {
                    tempID[k] = id[j][k];
                    id[j][k] = id[j+1][k];
                    id[j+1][k] = tempID[k];
                }
            }
        }
    }
    printf("\nRank\tStudent ID\tScore\n");
    for(i=0; i<size; i++)
    {
        printf("%d\t%s\t%d\n", i+1, id[i], score[i]);
    }
}