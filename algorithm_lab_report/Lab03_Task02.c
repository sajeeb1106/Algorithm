#include<stdio.h>

int main()
{
    int size, i, j, k, temp;

    printf("Enter number of products: ");
    scanf("%d", &size);

    char name[size][50];
    int price[size];

    for(i=0; i<size; i++)
    {
        printf("\nEnter product name %d: ", i+1);
        scanf("%49s", name[i]);

        printf("Enter product price: ");
        scanf("%d", &price[i]);
    }

    // Bubble Sort Logic (Ascending Order)
    for(i=0; i<size-1; i++)
    {
        for(j=0; j<size-i-1; j++)
        {
            if(price[j] > price[j+1])
            {
                temp = price[j];
                price[j] = price[j+1];
                price[j+1] = temp;

                char tempName[50];
                for(k=0; k<50; k++)
                {
                    tempName[k] = name[j][k];
                    name[j][k] = name[j+1][k];
                    name[j+1][k] = tempName[k];
                }
            }
        }
    }

    printf("\nProducts\tPrice\n");
    for(i=0; i<size; i++)
    {
        printf("%s\t\t%d\n", name[i], price[i]);
    }
}