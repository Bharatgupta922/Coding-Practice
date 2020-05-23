#include <iostream>
using namespace std;
int getnoOfone(string s)
{
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '1')
            count++;
    }
    return count;
}
string makeones(string s)
{
    string ones;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '0')
            ones[i] = '1';
        else
            ones[i] = '0';
    }
    return ones;
}
string maketwos(string ones)
{
    string twos;
    twos = ones;
    for (int i = ones.length() - 1; i >= 0; i--)
    {
        if (ones[i] == '1')
        {
            twos[i] = '0';
        }
        else
        {
            twos[i] = '1';
            break;
        }
    }
    return twos;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s, ones, twos, result;
        cin >> n;
        cin >> s;
        if (getnoOfone(s) == n)
        {
            cout << "-1";
        }
        else
        {
            ones = makeones(s);
            twos = maketwos(ones);
            if (getnoOfone(ones) > getnoOfone(twos))
            {
                result = ones;
            }
            else
            {
                result = twos;
            }
            cout << result;
        }
        cout << endl;
    }
    return 0;
}
