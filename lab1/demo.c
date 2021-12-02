#include <stdio.h>
#include <stdlib.h>

#define n 5

int nonZero(int **a)
{
    int nonz = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                nonz++;
            }
        }
    }
    return nonz;
}

int sumLeadingD(int **a)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i][i];
    }
    return sum;
}

void displayMinorD(int **a)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j >= n - i - 1)
            {
                printf("%d", a[i][j]);
            }
        }
        printf("\n");
    }
}

void productD(int **a)
{
    int proL = 1, proR = 1;
    for (int i = 0; i < n; i++)
    {
        proL = proL * a[i][i];
        proR = proR * a[i][n - 1 - i];
    }

    printf("Left=%d\nRight=%d\nTotal=%d", proL, proR, proL * proR);
}

int main()
{
    int **A = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        A[i] = (int *)malloc(n * sizeof(int));
    printf("Enter elements in the array 1: \n ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter elements at position [%d,%d] : ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    printf("Non Zero Terms=%d\n",nonZero(A));
    printf("SUM Of Leading Diagnol=%d\n\n",sumLeadingD(A));
    displayMinorD(A);
    printf("\n");
    productD(A);

    return 0;
}