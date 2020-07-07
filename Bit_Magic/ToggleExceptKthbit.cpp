#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        printf("%d\n", ~(n ^ (1 << k)));
    }

    return 0;
}