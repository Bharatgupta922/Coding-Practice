#include <bits/stdc++.h>
using namespace std;

// this algorithm is used for finding the majority element in an array
// Majority Element  - is that which comes more than floor(length_of_Array/2) in an array

// Ist Method is that for every element you can check every element in an array O(n^2)
// IInd Method is that we can use HashMap get the count of each element the check and return
// IIIrd is Moore's Voting Algorithm  we use here

int MooresVotingAlgorithm(vector<int> &nums)
{
    // int count = 0;
    // int candidate = 0;

    // for (auto x : nums)
    // {
    //     if (count == 0)
    //     {
    //         candidate = x;
    //     }

    //     if (candidate == x)
    //         count += 1;
    //     else
    //         count -= 1;
    // }
    // return candidate;

    int count = 0;
    int candidate = 0;
    for (auto x : nums)
    {
        if (count == 0)
            candidate = x;
        if (candidate == x)
            ++count;
        else
            --count;
    }
    return candidate;
}

int main()
{


// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    int t;
    cin >> t;
    while (t--)
    {
        vector<int> nums;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> nums[i];
        }
        cout << "The Majority Element is " << MooresVotingAlgorithm(nums) << endl;
    }
    return 0;
}