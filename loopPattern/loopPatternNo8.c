/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    char c;
    int n;
    scanf("%d", &n);
    int a = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = (65 + a); j <= (64 + n); j++)
        {
            printf(" %c ", j);
        }
        a++;
        printf("\n");
    }

    return 0;
}
