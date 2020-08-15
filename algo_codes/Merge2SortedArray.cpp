#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
void printTheVector(vector<int> vec)
{

    for (auto x : vec)
        cout << x << " ";
    cout << endl;
}
void printTheVector(vector<int> first, vector<int> second)
{

    for (auto x : first)
        cout << x << " ";
    for (auto x : second)
        cout << x << " ";
    cout << endl;
}
void naive(vector<int> first, vector<int> second)
{

    vector<int> temp;

    for (auto it = first.begin(); it != first.end(); ++it)
    {
        temp.push_back(*it);
    }

    for (auto it = second.begin(); it != second.end(); ++it)
    {
        temp.push_back(*it);
    }

    sort(temp.begin(), temp.end());

    printTheVector(temp);
}
void method2(vector<int> first, vector<int> second)
{
    for (int i = 0; i < first.size(); ++i)
    {
        if (first[i] > second[0])
        {
            swap(first[i], second[0]);
            int y = 0;
            for (int j = 1; j < second.size(); ++j)
            {
                if (second[y] > second[j])
                {
                    swap(second[y++], second[j]);
                }
                else
                {
                    break;
                }
            }
        }
    }
    printTheVector(first, second);
}
void method3(vector<int> first, vector<int> second)
{
    int gap = ceil((first.size() + second.size()) / 2);
    int i, j;
    while (gap != 1)
    {
        i = 0;
        j = gap;
        for (int x = gap; x < (first.size() + second.size()); ++x)
        {
            if ()
        }

        gap = ceil(gap / 2);
    }
}
int main()
{

    int n, m;
    cin >> m >> n;
    vector<int> vec1(m, 0);
    vector<int> vec2(n, 0);
    for (int i = 0; i < m; ++i)
    {
        cin >> vec1[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> vec2[i];
    }
    //   naive(vec1, vec2);
    method2(vec1, vec2);
    return 0;
}

// geeks for geeks attempt

// #include <iostream>
// #include<algorithm>
// #include<vector>
// #define ll long long
// using namespace std;
// void printTheVector(ll * first, ll * second, ll m, ll n) {

//     for (int i = 0; i < m; ++i)cout<<first[i]<<" ";
//     for (int i = 0; i < n; ++i)cout<<second[i]<<" ";

//     cout<<endl;

// }
// void method2(ll * first, ll * second, ll m, ll n) {
//     ll i = m - 1;
//     ll j = 0;
//     while (j < n && i>=0) {
//         if (first[i] > second[j])
//             swap(first[i], second[j]);
//         else break;
//         --i;
//         ++j;
//     }
//     sort(first, first + m);
//     sort(second, second + n);
//     printTheVector(first, second, m, n);
// }
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     //code
//     int t;
//     cin>>t;
//     while (t--) {
//         ll n, m;
//         cin>>m>>n;
//         ll * vec1 = new ll[m];
//         ll * vec2 = new ll[n];
//         for (ll i = 0; i < m; ++i) {
//             cin>>vec1[i];
//         }
//         for (ll i = 0; i < n; ++i) {
//             cin>>vec2[i];
//         }
//         //   naive(vec1, vec2);
//         method2(vec1, vec2, m, n);
//     }
//     return 0;
// }