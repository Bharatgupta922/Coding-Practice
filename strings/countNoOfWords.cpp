#include <iostream>
#include <sstream>
using namespace std;

int countWords(string str)
{
    // breaking input into word using string stream
    stringstream s(str); // Used for breaking words
    string word;         // to store individual words

    int count = 0;
    while (s >> word)
    {
        count++;
    }

    return count;
}
int main()
{

    string s;
    getline(cin, s);
    cout << countWords(s) << endl;

    return 0;
}