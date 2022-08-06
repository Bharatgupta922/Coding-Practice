#include <bits/stdc++.h>
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define f(x, n) for (int x = 0; x < n; ++x)

int main()
{
    fastio();
vector<int> nums;
int sum ;

    int n = nums.size();
        int ** dp = new int*[n+1];
        for(int i = 0  ; i < n + 1 ; ++i)
            dp[i] = new int[sum+1];
        for(int i = 0 ; i < n + 1 ; ++i){
            for(int j = 0  ;  j < sum + 1 ; ++j){
                if(i == 0)dp[i][j] = 0 ;
                if(j == 0)dp[i][j] = 1;
            }
        }
        for(int i = 1;  i < n + 1; ++i){
            for(int j = 1 ;  j < sum + 1 ; ++j){
                if(nums[i-1] <= sum)
                    dp[i][j] = dp[i][j] + dp[i][j-nums[i-1]];
                else dp[i][j] = dp[i-1][j];
            }
        }
        int res = dp[n+1][sum];
        for(int i = 0 ;  i < n + 1 ; ++i)
            delete[] dp[i];
        delete dp;
        return res;
    return 0;
}