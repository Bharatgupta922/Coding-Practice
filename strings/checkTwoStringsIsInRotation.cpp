#include <iostream>
using namespace std;
bool check(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    string temp = "";
    temp = s1 + s1;
    return temp.find(s2) != string::npos;
}
int main()
{
    string s1 = "Bharat";
    string s2 = "Bhraat";
    // check whether the strings are in rotation or not
    if (check(s1, s2))
        cout << "yes ,string are in rotation";
    else
        cout << "no , string are not in rotation or differnet ";
    return 0;
}
