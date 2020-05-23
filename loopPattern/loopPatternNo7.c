/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
int func(int i, int j);
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            printf("  ");
        for (int j = 1; j <= i; j++)
            printf("%d   ", func(i, j));
        printf("\n");
    }
    return 0;
}
int func(int i, int j)
{
    if (j == i || j == 1)
        return 1;
    else
        return func(i - 1, j - 1) + func(i - 1, j);
}
