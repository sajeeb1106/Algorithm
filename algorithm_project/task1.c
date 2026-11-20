#include <stdio.h>
#include <string.h>

#define MAX 100
#define FILE_NAME "relief_requests.txt"

typedef struct{
    int requestID;
    char community[50];
    int affectedPeople;
}ReliefRequest;

int iterativeSum(ReliefRequest requests[], int n) 
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += requests[i].affectedPeople;
    }
    return total;
}

int recursiveSum(ReliefRequest requests[], int n) 
{
    if (n == 0) 
    {
        return 0;
    }
    return requests[n - 1].affectedPeople + recursiveSum(requests, n - 1);
}

int iterativeLinearSearch(ReliefRequest requests[], int n, int targetID) 
{
    for (int i = 0; i < n; i++)
    {
        if (requests[i].requestID == targetID) 
        {
            return i;
        }
    }
    return -1;
}

int recursiveLinearSearch(ReliefRequest requests[], int n, int targetID) 
{
    if (n == 0)
    {
        return -1;
    } 
    if (requests[n - 1].requestID == targetID)
    {
        return n - 1;
    } 
    return recursiveLinearSearch(requests, n - 1, targetID);
}

void displayRequests(ReliefRequest requests[], int n) 
{
    if (n == 0) 
    {
        printf("\nNo relief requests available.\n");
        return;
    }

    printf("\n%-12s %-25s %-16s\n", "Request ID", "Community", "Affected People");
    for (int i = 0; i < n; i++)
    {
        printf("%-12d %-25s %-16d\n", requests[i].requestID, requests[i].community, requests[i].affectedPeople);
    }
}

void saveRequests(ReliefRequest requests[], int n) 
{
    FILE *fp = fopen(FILE_NAME, "w");
    if (fp == NULL) 
    {
        printf("Error: Could not save the file.\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d|%s|%d\n", requests[i].requestID, requests[i].community, requests[i].affectedPeople);
    }
    fclose(fp);
}

int loadRequests(ReliefRequest requests[]) 
{
    FILE *fp = fopen(FILE_NAME, "r");
    int n = 0;
    if (fp == NULL)
    {
        return 0;
    }
    while (n < MAX && fscanf(fp, "%d|%49[^|]|%d\n", &requests[n].requestID, requests[n].community, &requests[n].affectedPeople) == 3)
    {
        n++;
    }
    fclose(fp);
    return n;
}

int main() 
{
    ReliefRequest requests[MAX];
    int n = loadRequests(requests);
    int choice, targetID, index;

    do {
        printf("\nTASK 1: RELIEF REQUEST MANAGEMENT\n");
        printf("1. Add relief request\n");
        printf("2. Display all requests\n");
        printf("3. Calculate total (Iterative and Recursive)\n");
        printf("4. Search Request ID (Iterative and Recursive)\n");
        printf("5. Save requests\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) 
        {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice) 
        {
            case 1:
                if (n >= MAX) 
                {
                    printf("Request storage is full.\n");
                    break;
                }
                printf("Enter unique Request ID: ");
                scanf("%d", &requests[n].requestID);
                if (iterativeLinearSearch(requests, n, requests[n].requestID) != -1) 
                {
                    printf("This Request ID already exists.\n");
                    break;
                }
                printf("Enter community name (one word): ");
                scanf("%49s", requests[n].community);
                printf("Enter number of affected people: ");
                if (scanf("%d", &requests[n].affectedPeople) != 1 || requests[n].affectedPeople < 0) 
                {
                    printf("Invalid number. Request was not added.\n");
                    break;
                }
                n++;
                printf("Request added successfully.\n");
                break;

            case 2:
                displayRequests(requests, n);
                break;

            case 3:
                if (n == 0) 
                {
                    printf("No data available.\n");
                    break;
                }
                printf("Total affected people (Iterative): %d\n", iterativeSum(requests, n));
                printf("Total affected people (Recursive): %d\n", recursiveSum(requests, n));
                break;

            case 4:
                printf("Enter Request ID to search: ");
                scanf("%d", &targetID);

                index = iterativeLinearSearch(requests, n, targetID);
                if (index != -1)
                    printf("Iterative Search: Found at position %d, Community: %s, Affected: %d\n",index + 1, requests[index].community, requests[index].affectedPeople);
                else
                    printf("Iterative Search: Request not found.\n");

                index = recursiveLinearSearch(requests, n, targetID);
                if (index != -1)
                    printf("Recursive Search: Found at position %d, Community: %s, Affected: %d\n", index + 1, requests[index].community, requests[index].affectedPeople);
                else
                    printf("Recursive Search: Request not found.\n");
                break;

            case 5:
                saveRequests(requests, n);
                printf("Requests saved to %s.\n", FILE_NAME);
                break;

            case 0:
                saveRequests(requests, n);
                printf("Data saved. Exiting Task 1.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);
}