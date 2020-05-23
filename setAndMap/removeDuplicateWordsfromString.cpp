#include <iostream>
#include <sstream>
#include <unordered_set>
using namespace std;
int main()
{

    string s, word;
    cout << "enter the string " << endl;
    getline(cin, s); // b/c cin not get the string with spaces
    unordered_set<string> hsh;
    stringstream ss(s); // used to split the sentence into words
    do
    {
        ss >> word;
        if (hsh.find(word) == hsh.end())
        {
            cout << word << " ";
            hsh.insert(word);
        }
    } while (ss);
    return 0;
}