/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <limits.h>
int main()
{
    char s[1000];
    scanf("%s", s);
    int count[256] = {0};
    int length = strlen(s);
    // int length=0;                              ////// this section is for counting the no. of characters in array s
    // for(int i =0;s[i]!='\0';i++)               //////  if we do not want to include the string.h file
    // length++;                                  //////
    for (int i = 0; i < length; i++)
        count[s[i]]++;
    int max = -1;
    char result;
    for (int i = 0; i < length; i++)
        if (max < count[s[i]])
        {
            max = count[s[i]];
            result = s[i];
        }
    printf("%c", result);
    return 0;
}
