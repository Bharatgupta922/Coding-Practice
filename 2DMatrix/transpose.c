#include <stdio.h>
int main()
{
    int m, n;
    printf("enter the no. of rows you want \n");
    scanf("%d", &m);
    printf("enter the no. of columns you want \n");
    scanf("%d", &n);
    int a[m][n];
    printf("ENTER THE MATRIX THAT TO BE TRNSPOSED :\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    printf("TRANSPOSE OF MATRIX IS :\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d\t", a[j][i]);
        printf("\n");
    }

    return 0;
}
