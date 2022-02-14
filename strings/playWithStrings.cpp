#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{

    // string str;
    // string str1(5, 'b');
    // string str2 = "BharatGupta";
    // cout << str1 << endl
    //      << str2 << endl;

    // //to get string with spaces
    // string str3;
    // getline(cin, str3);
    // cout << str3 << endl;

    // string str;

    // string s1 = "fam";
    // string s2 = "ily";
    // cout << s1 + s2 << endl;
    // s1.append(s2); // s1 = s1 + s2 or s1 += s2
    // cout << s1 << " " << s2 << endl;
    // cout << s1[2] << endl;

    // string abc = " lhbalbv ;jf; dvkhbdl";
    // abc.clear();
    // cout << abc << endl;

    // string s1 = "abc";
    // string s2 = "abc";
    // cout << s2.compare(s1) << endl;
    // if (!s2.compare(s1))
    //     cout << "strings aren't equal " << endl;
    // s2.clear();
    // if (s2.empty())
    // {
    //     cout << "stirng is empty" << endl;
    // }

    // string s1 = "nincompoop";
    // s1.erase(2, 3);
    // cout << s1 << endl;

    // string s1 = "nincompoop";

    // cout << s1.find("poo") << endl;

    // string s1 = "nincompoop";
    // s1.insert(3, "shit");
    // cout << s1 << endl
    //      << s1.size() << endl;

    // string s1 = "nincompoop";
    // string s = s1.substr(6, 4);
    // cout << s << endl;

    // string x = "222";
    // int y = stoi(x);
    // cout << y + 2 << endl;

    // cout << to_string(y) + "5s" << endl;

    string s2 = "kjasbklfalbka64464";
    sort(s2.begin(), s2.end());
    cout << s2 << endl;

    transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
    cout << s2 << endl;

    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    cout << s2 << endl;

    string x = "64466449787981";
    sort(x.end(), x.begin(), greater<int>());
    cout << x << endl;

    return 0;
}