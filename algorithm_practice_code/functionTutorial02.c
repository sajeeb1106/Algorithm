#include <stdio.h>

int sq(int a)
{
    return a * a;
}

int main() 
{
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    int result = sq(num);

    printf("Answer: %d\n", result);
}