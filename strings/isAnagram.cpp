#include <iostream>
#include <cstring>
#include <cstdbool>
using namespace std;
bool isanagram(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    int ascii[256] = {0};
    for (int i = 0; i < s1.length(); i++)
        ++ascii[s1[i]];
    for (int i = 0; i < s2.length(); i++)
        --ascii[s1[i]];
    for (int i = 0; i < 256; i++)
        if (ascii[i] > 0)
            return false;
    return true;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    isanagram(s1, s2) ? cout << "anagram" : cout << "not anagram";
    return 0;
}
