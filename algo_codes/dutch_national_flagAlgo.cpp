#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printvector(vector<int> vec){
    for(auto x : vec)cout<<x<<" ";
    cout<<endl;
}
void dutch(vector<int> &vec)
{
    int low = 0, mid = 0, high = vec.size() - 1;
    while (mid <= high)
    {
        switch (vec[mid])
        {
        case 0:
            swap(vec[low++], vec[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(vec[mid], vec[high--]);
            break;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];
    dutch(vec);
    printvector(vec);

    return 0;
}