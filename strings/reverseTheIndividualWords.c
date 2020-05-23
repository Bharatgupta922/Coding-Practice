#include <stdio.h>
#include <string.h>
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(int lb, char *str, int ub)
{
    while (lb < ub)
        swap(&str[lb++], &str[ub--]);
}
void revthewords(char str[])
{
    int i = 0;
    while (str[i])
    {
        int j = i;
        while (str[j] != ' ' && str[j])
            j++;
        reverse(i, str, j - 1);
        i = j;
        while (str[i] == ' ')
            i++;
    }
    printf("%s", str);
}
int main()
{
    char str[50];
    scanf("%[^\n]s", str);
    revthewords(str);

    return 0;
}
