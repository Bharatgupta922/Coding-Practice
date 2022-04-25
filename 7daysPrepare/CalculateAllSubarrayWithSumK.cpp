#include<bits/stdc++.h>
using namespace std;
int main(){

    int k  = 6;
    int a[] = {2,1,3,5,0,2,4};
    int i = 0  , j = 0  , sum =  0 ;
    int n = sizeof(a)/sizeof(a[0]);
    while(j<n){
        sum += a[j];
        j++;
        if(sum > k){
            while(i<j && sum > k){
                sum -= a[i];
                i++;
            }
        }
        if(sum == k){
            cout<<i<<", "<<j-1<<endl;
        }
    }
}