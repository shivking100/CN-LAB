#include <stdio.h>

void swap(int *num1, int *num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main()
{
    int n1, n2;

    printf("\nEnter the 1st number : ");
    scanf("%d", &n1);
    printf("\nEnter the 2nd number : ");
    scanf("%d", &n2);

    swap(&n1, &n2);

    printf("\nFirst number  : %d", n1);
    printf("\nSecond number : %d", n2);
    printf("\n");

    return (0);
}