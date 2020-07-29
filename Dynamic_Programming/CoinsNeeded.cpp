#include<bits/stdc++.h>
using namespace std ;

int coinsNeeded(int a[] , int amount , int n ){

    if(amount == 0)return 0 ;


    int ans = INT_MAX;
    for(int i = 0 ; i < n ; ++i){
        if(amount - a[i] >= 0){
            int smallerAns = coinsNeeded(a,amount - a[i] , n);
            if(smallerAns != INT_MAX){
                ans = min(ans , smallerAns + 1);
            }
        }
    }
    return ans ;
}


//dp approach bottom up 
int coinsNeededDP(int coins[] , int amount , int n){

    int *dp = new int[amount + 1];
   

for(int i = 0 ; i <= amount ; ++i){
    dp[i] = INT_MAX;
}
 dp[0] = 0 ;
    for(int rupay = 1 ; rupay <= amount ; ++rupay){

        for(int i = 0 ; i<n ; ++i){
            if(coins[i] <= rupay){
                int smaller = dp[rupay-coins[i]];

                if(smaller != INT_MAX){
                    dp[rupay] = min(dp[rupay] , smaller + 1);
                }
            }
        }
    }
    return dp[amount];
}



int main(){

int us_coins[] = {1,7,10};
// int n = 3 ;
// int amount = 15;
// cout<<coinsNeeded(us_coins , amount , n)<<endl;

int indian_coins[] = {1,2,5,10,20,50};
int n = 6;
int amount = 39;

//recursive solution
// cout<<coinsNeeded(indian_coins , amount , n)<<endl;


// using dp
cout<<coinsNeededDP(us_coins , amount , 3)<<endl;

    return 0 ; 
}