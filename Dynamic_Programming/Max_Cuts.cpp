#include<iostream>
using namespace std ;
int MaxCuts(int n , int a , int b , int c){
    int dp[n+1];
    dp[0] = 0;
    for(int i = 1 ; i <= n ; ++i){
        dp[i] = -1;
        if(i-a>=0){
            dp[i] = max(dp[i] , dp[i-a]);
        }
        if(i-b >= 0){
            dp[i] = max(dp[i] , dp[i-b]);
        }
        if(i-c >= 0){
            dp[i] = max(dp[i] , dp[i-c]);
        }
    }
    return dp[n]; 
}
int main(){
    int t ;
    cin>>t;
    while(t--){
        int n  , a,b,c;
        cin>>n>>a>>b>>c;
        cout<<MaxCuts(n,a,b,c)<<endl;
    }
}