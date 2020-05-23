/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
int main()
{
    int m, n;
    printf("enter the no. of rows you want:\n");
    scanf("%d", &m);
    printf("enter the no. of columns you want:\n");
    scanf("%d", &n);
    int a[m][n];
    printf("enter the values in the matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    printf("your lower trianngular matrix is :\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            if (i < j)
                printf("0 ");
            else
                printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
    printf("your upper trianngular matrix is :\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            if (i > j)
                printf("0 ");
            else
                printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}
