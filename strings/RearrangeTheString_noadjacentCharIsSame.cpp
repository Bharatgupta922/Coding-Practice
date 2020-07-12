// Rearrange characters in a string such that no two adjacent are same
// Given a string with repeated characters, the task is to rearrange characters
// in a string so that no two adjacent characters are same.


//sample test cases 

// Input: aaabc 
// Output: abaca 

// Input: aaabb
// Output: ababa 

// Input: aa 
// Output: Not Possible

// Input: aaaabc 
// Output: Not Possible


#include <bits/stdc++.h>
using namespace std;
//this class or structure makes the priority queue
//sort by second element of pair
struct myComp
{
    constexpr bool operator()(pair<int, int> const &a, pair<int, int> const &b)
        const noexcept
    {
        return a.second < b.second;
    }
};
void rearrange(string s)
{
    string op = "";
    priority_queue<pair<char, int>, vector<pair<char, int>>, myComp> pq;
    int freq[26] = {0};
    for (int i = 0; i < s.length(); ++i)
    {
        ++freq[s[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i)
    {
        if (freq[i] > 0)
        {
            pq.push(make_pair(i + 'a', freq[i]));
        }
    }
    pair<char, int> lastvis;
    lastvis.first = '#';
    lastvis.second = -1;
    while (!pq.empty())
    {
        pair<char, int> temp = pq.top();
        pq.pop();
        op.push_back(temp.first);
        --temp.second;
        if (lastvis.second > 0)
        {
            pq.push(lastvis);
        }
        lastvis = temp;
    }
    if (op.length() == s.length())
    {
        cout << op << endl;
    }
    else
    {
        cout << "it cannnot be rearranged!" << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        rearrange(s);
    }
}