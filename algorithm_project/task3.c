#include <stdio.h>

#define MAX 100
typedef struct {
    char packageName[20];
    double weight;
    double value;
    double ratio;
} Package;

void sortByRatioDescending(Package packages[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (packages[j].ratio < packages[j + 1].ratio) 
            {
                Package temp = packages[j];
                packages[j] = packages[j + 1];
                packages[j + 1] = temp;
            }
        }
    }
}

void fractionalKnapsack(Package packages[], int n, double capacity) 
{
    double remaining = capacity;
    double totalWeight = 0.0;
    double totalValue = 0.0;

    sortByRatioDescending(packages, n);

    printf("\nPackages arranged by value-to-weight ratio:\n");
    printf("%-12s %-12s %-12s %-12s\n","Package", "Weight", "Value", "Ratio");
    for (int i = 0; i < n; i++)
    {
        printf("%-12s %-12.2f %-12.2f %-12.2f\n", packages[i].packageName, packages[i].weight, packages[i].value, packages[i].ratio);
    }

    printf("\nSelected packages:\n");
    printf("%-12s %-15s %-15s %-15s\n", "Package", "Taken Weight", "Fraction", "Value Gained");

    for (int i = 0; i < n && remaining > 0.000001; i++) 
    {
        double takenWeight, fraction, gainedValue;

        if (packages[i].weight <= remaining) 
        {
            takenWeight = packages[i].weight;
            fraction = 1.0;
        } 
        else 
        {
            takenWeight = remaining;
            fraction = remaining / packages[i].weight;
        }

        gainedValue = packages[i].value * fraction;
        totalWeight += takenWeight;
        totalValue += gainedValue;
        remaining -= takenWeight;

        printf("%-12s %-15.2f %-15.2f %-15.2f\n", packages[i].packageName, takenWeight, fraction, gainedValue);
    }

    printf("\nMaximum capacity: %.2f kg\n", capacity);
    printf("Total selected weight: %.2f kg\n", totalWeight);
    printf("Maximum achievable relief value: %.2f\n", totalValue);
    printf("Unused capacity: %.2f kg\n", remaining);
}

int main() 
{
    Package packages[MAX];
    int n;
    double capacity;

    printf("TASK 3: FRACTIONAL KNAPSACK\n");
    printf("Enter number of packages (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) 
    {
        printf("Invalid number of packages.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) 
    {
        printf("\nPackage %d\n", i + 1);

        printf("Enter package name (e.g., P1): ");
        scanf("%19s", packages[i].packageName);

        printf("Enter weight in kg: ");
        scanf("%lf", &packages[i].weight);

        printf("Enter relief value: ");
        scanf("%lf", &packages[i].value);

        if (packages[i].weight <= 0 || packages[i].value < 0) 
        {
            printf("Weight must be positive and value cannot be negative.\n");
            return 1;
        }
        packages[i].ratio = packages[i].value / packages[i].weight;
    }

    printf("\nEnter warehouse transportation capacity (kg): ");
    if (scanf("%lf", &capacity) != 1 || capacity < 0)
    {
        printf("Invalid capacity.\n");
        return 1;
    }
    fractionalKnapsack(packages, n, capacity);
}