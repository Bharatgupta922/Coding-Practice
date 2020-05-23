#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
void deleteduplicates(char *s)
{
    unordered_map<char, int> m;
    int index = 0;
    for (int i = 0; s[i]; i++)
        if (m[s[i]] == 0)
        {
            m[s[i]]++;
            s[index++] = s[i];
        }
    s[m.size()] = '\0';
}
// if you want to print the output in alphabetical order the you can use set with pair
int main()
{
    char s[] = "Bharat";
    deleteduplicates(s);
    cout << s;
    return 0;
}
