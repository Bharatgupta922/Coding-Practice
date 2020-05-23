/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    int a[m][n], b[m][n], temp[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &b[i][j]);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = a[i][j];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] -= b[i][j];
    bool y = true;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (temp[i][j] != 0)
            {
                y = false;
                break;
            }
    if (y)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%d ", 2 * a[i][j]);
            printf("\n");
        }
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%d ", temp[i][j]);
            printf("\n");
        }
    }

    return 0;
}
