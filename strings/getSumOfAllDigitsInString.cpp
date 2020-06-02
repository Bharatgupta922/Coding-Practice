#include <iostream>
#include <string>

using namespace std;
int getSum(string s)
{
    int result = 0;
    int j;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            j = i;
            while (s[i] >= '0' && s[i] <= '9')
            {
                j++;
            }
            string temp = s.substr(i,j-i);
            result += atoi(temp.c_str());
            i = j;
        }
    }
    return result;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << getSum(s) << endl;
    }
    return 0;
}