#include <iostream>
using namespace std;
void print(char *s, int i)
{
    if (s[i] >= 'A' && s[i] <= 90)
    {
        cout << s[i];
        return;
    }
    else
        return print(s, ++i);
}
int main()
{
    char s[50] = "bharat is a gooD boy";
    print(s, 0);
    return 0;
}