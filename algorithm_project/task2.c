#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int requestID;
    char community[50];
    int priority;
    int affectedPeople;
} ReliefRequest;

int comesBefore(ReliefRequest a, ReliefRequest b, int mode) 
{
    if (mode == 0)
    {
        return a.priority >= b.priority;
    }
    else
    {
        return a.requestID <= b.requestID;
    }
}

void merge(ReliefRequest arr[], ReliefRequest temp[], int left, int mid, int right, int mode) 
{
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) 
    {
        if (comesBefore(arr[i], arr[j], mode))
        {
            temp[k++] = arr[i++];
        } 
        else 
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) 
    {
        temp[k++] = arr[i++];
    }
    while (j <= right) 
    {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(ReliefRequest arr[], ReliefRequest temp[], int left, int right, int mode) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, temp, left, mid, mode);
        mergeSort(arr, temp, mid + 1, right, mode);
        merge(arr, temp, left, mid, right, mode);
    }
}

int binarySearchByID(ReliefRequest arr[], int n, int targetID) 
{
    int low = 0, high = n - 1;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (arr[mid].requestID == targetID)
        {
            return mid;
        } 
        if (arr[mid].requestID < targetID)
        {
            low = mid + 1;
        } 
        else 
        {
            high = mid - 1;
        } 
    }
    return -1;
}

void display(ReliefRequest arr[], int n) 
{
    printf("\n%-12s %-22s %-12s %-16s\n", "Request ID", "Community", "Priority", "Affected People");
    for (int i = 0; i < n; i++)
    {
        printf("%-12d %-22s %-12d %-16d\n", arr[i].requestID, arr[i].community, arr[i].priority, arr[i].affectedPeople);
    }
}

int main() 
{
    ReliefRequest requests[MAX], temp[MAX], idSorted[MAX];
    int n, targetID, index;

    printf("TASK 2: MERGE SORT AND BINARY SEARCH\n");
    printf("Enter number of relief requests (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) 
    {
        printf("Invalid number of requests.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) 
    {
        printf("\nRequest %d\n", i + 1);

        printf("Enter unique Request ID: ");
        scanf("%d", &requests[i].requestID);

        printf("Enter community name (one word): ");
        scanf("%49s", requests[i].community);

        printf("Enter priority level (higher number = higher priority): ");
        scanf("%d", &requests[i].priority);

        printf("Enter affected people: ");
        scanf("%d", &requests[i].affectedPeople);
    }
    mergeSort(requests, temp, 0, n - 1, 0);
    printf("\nRelief requests sorted by descending priority:\n");
    display(requests, n);

    for (int i = 0; i < n; i++)
    {
        idSorted[i] = requests[i];
    }

    mergeSort(idSorted, temp, 0, n - 1, 1);
    printf("\nEnter Request ID to search: ");
    scanf("%d", &targetID);

    index = binarySearchByID(idSorted, n, targetID);
    if (index != -1) 
    {
        printf("\nRequest found:\n");
        printf("Request ID: %d\n", idSorted[index].requestID);
        printf("Community: %s\n", idSorted[index].community);
        printf("Priority: %d\n", idSorted[index].priority);
        printf("Affected People: %d\n", idSorted[index].affectedPeople);
    } 
    else
    {
        printf("Request ID %d was not found.\n", targetID);
    }
}