#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    int a, b, c, highestdivisor = INT_MIN, lcm;
    scanf("%d", &a);
    scanf("%d", &b);
    if (b < 0)
    {
        c = -a;
        printf("%d", c);
    }
    else
    {
        if (abs(a) > abs(b))
        {
            for (int i = 1; i <= abs(a); i++)
            {
                if (a % i == 0 && b % i == 0)
                {
                    if (highestdivisor < i)
                    {
                        highestdivisor = i;
                    }
                }
            }
        }
        else
        {
            for (int i = 1; i <= abs(b); i++)
            {
                if (a % i == 0 && b % i == 0)
                {
                    if (highestdivisor < i)
                    {
                        highestdivisor = i;
                    }
                }
            }
        }
        printf("%d\n", highestdivisor);
    }
    lcm = (a * b) / highestdivisor;
    printf("%d", lcm);

    return 0;
}
