#include<bits/stdc++.h> 
using namespace std; 
   
long long solve1(long long m){ 
    for(long long i = 0 ; i < m/2 + 1 ; i++){ 
        if(m < pow(2,i)){ 
            return i; 
        } 
    } 
    return 0; 
} 
 
vector<char> solve_change(vector<char> &s){ 
    vector<char> res; 
    for(char x : s){ 
        if(x == 'a' or x == 'd'){ 
            res.push_back('a'); 
            res.push_back('b'); 
        } 
        else if(x == 'c' or x == 'b'){ 
            res.push_back('c'); 
            res.push_back('d'); 
        } 
    } 
    return res; 
} 

int main(){ 
   
   int n ;
   cin>>n;
   int temp = 1;
   int j = 1;
   while(temp<n){
     temp += j;
     j*=2;
   }
  cout<<temp;
    return 0; 
}
