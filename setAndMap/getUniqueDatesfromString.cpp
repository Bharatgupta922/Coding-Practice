#include <iostream>
#include <unordered_set>
using namespace std;
int getUniqueDate(string s)
{
    string store;
    unordered_set<string> us;
    for (int i = 0; s[i]; i++)
    {
        if (isdigit(s[i]))
            store.push_back(s[i]);

        if (s[i] == '-')
            store.clear();

        if (store.length() == 4)
        {
            us.insert(store);
            store.clear();
        }
    }
    return us.size();
}
int main()
{
    cout << "Enter the string" << endl;
    string s;
    getline(cin, s); //it will catch space also
    cout << s << endl
         << getUniqueDate(s) << endl;
    return 0;
}