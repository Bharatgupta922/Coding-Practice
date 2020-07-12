#include <iostream>
using namespace std;
void printSub(string s, string curr = "", int index = 0)
{
    if (index == s.length())
    {
        cout << "'" << curr << "'"
             << ","
             << " ";
        return;
    }
    printSub(s, curr, index + 1);
    printSub(s, curr + s[index], index + 1);
      
}
int main()
{
    string s ;
    cin>>s;
    printSub(s);
    return 0;
}