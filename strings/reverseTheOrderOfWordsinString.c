#include <stdio.h>
#include <string.h>
int main()
{
    char str[100] = "codequotiennt loves codes";
    char ans[100] = "";
    int i = strlen(str) - 1, y = 0;
    while (i >= 0)
    {
        while (i >= 0 && str[i] == ' ')
            i--;
        int j = i;
        if (i < 0)
            break;
        while (i >= 0 && str[i] != ' ')
            i--;
        if (!strcmp(ans, ""))
        {
            int k = i + 1;
            while (k <= j)
                ans[y++] = str[k++];
        }
        else
        {
            ans[y++] = ' ';
            int k = i + 1;
            while (k <= j)
                ans[y++] = str[k++];
        }
    }
    printf("%s", ans);
    return 0;
}
