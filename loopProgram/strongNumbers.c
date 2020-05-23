/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{

    int n, a, b, fact, sum;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        a = i;

        sum = 0;
        while (a > 0)
        {
            b = a % 10;
            fact = 1;
            for (int j = b; j > 0; j--)
            {
                fact = fact * j;
            }
            sum += fact;
            a /= 10;
        }
        if (sum == i)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}
