#include <stdio.h>

int sum(int a, int b) 
{
    return a + b;
}
int main() 
{
    int num1, num2;
    printf("Enter first integer: ");
    scanf("%d", &num1);
    
    printf("Enter second integer: ");
    scanf("%d", &num2);

    printf("Total = %d\n", sum(num1, num2));
}
