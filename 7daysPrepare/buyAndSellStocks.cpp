#include<bits/stdc++.h>
using namespace std;
int buySell1(int a[],int n ){

// bruteforce by 2 loops o(n^2)
//by auxilurry aray o(n) & sc- o(n)
//this is real tc- o(n) && sc - o(1)
//can only buy and sell one time
//calculate profit
int ans = 0;
int minSofar = a[0];

for(int i = 0 ;  i < n  ; ++i){
    minSofar = min(minSofar , a[i]);
    ans = max(ans , a[i]-minSofar);
}
return ans;
}
int buySell2(int a[],int n){
    //you can sell any number of times   : max profit  ?? 
    int profit =0 ;
    for(int i =  1 ; i < n ; ++i)
        if(a[i] > a[i-1])
            profit+=(a[i]-a[i-1]);
    return profit;
}
int buySell3(int a[],int n,int k){
    //you can sell atmost k times   : max profit  ?? 
    vector<int> mn(k+1,INT_MAX);
        vector<int> profit(k+1,0);
        
        for(int i = 0 ;  i < n ; ++i){
            for(int j=1;j<k+1;j++){
                mn[j]=min(mn[j],a[i]-profit[j-1]);
                profit[j]=max(profit[j],a[i]-mn[j]);
            }
        }
        return profit[k];
}

int main(){
// 6
// 3 2 6 5 0 3

    #ifndef ONLINE_MODE
       freopen("input.txt" , "r", stdin);
       freopen("output.txt","w",stdout); 
    #endif

    int n ;
    cin>>n;
    int a[n];
    for(int i = 0  ; i < n  ; ++i){
        cin>>a[i];
    }

    // int k;cin>>k;

    cout<<buySell1(a,n)<<endl;
    cout<<buySell2(a,n)<<endl;
    // cout<<buySell3(a,n,k)<<endl;
    return 0;
}