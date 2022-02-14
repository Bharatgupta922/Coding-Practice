#include <iostream>
using namespace std;
void printSubSeq(string s, string curr = "", int index = 0)
{
    if (index == s.length())
    {
        cout << "'" << curr << "'"
             << " , ";
        return;
    }
    printSubSeq(s, curr, index + 1);
    printSubSeq(s, curr + s[index], index + 1);
    printSubSeq(s, curr + to_string((int)s[index]), index + 1);
}
int main()
{

    printSubSeq("ABC");

    return 0;
}