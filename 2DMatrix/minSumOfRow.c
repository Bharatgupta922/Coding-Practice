/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <limits.h>

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    int a[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    int temp = INT_MAX;
    int pos = 0, sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += a[i][j];
        }
        if (temp > sum)
        {
            temp = sum;
            pos++;
        }
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (i == pos - 1)
                printf("%d ", a[i][j]);

    return 0;
}
