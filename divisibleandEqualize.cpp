#include<bits/stdc++.h>
using namespace std;
void primeFactors(unordered_map<int, int> &mp) 
{ 
    // Print the number of 2s that divide n 
    int n;
    cin>>n;
    
    while (n % 2 == 0) 
    { 
        mp[2]++; 
        n = n/2; 
    } 
 for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 
        while (n % i == 0) 
        { 
            mp[i]++; 
            n = n/i; 
        } 
    } 
 if (n > 2) 
        mp[n]++; 
} 

int main() {
    int t;cin>>t;
    while(t--) {
        int n ;
        cin>>n;
        int a[n];
        unordered_map<int, int> mp;
        for (int i = 0 ; i < n ; ++i) {
            primeFactors(mp);
        }
        bool ans = true;
        for (auto it : mp) {
            if (it.second %n != 0) {
                cout<<"NO";
                ans = false;
                break;
            }
        }
    if (ans) cout<<"YES";
    cout<<endl;
        
    }
}