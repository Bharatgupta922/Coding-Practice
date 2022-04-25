#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
vector<ll> countElements(vector<string> elements){
    vector<ll> count; 
    int i = 0  ;
    for(int i = 0  ;  i < (int)elements.size() ; ++i){
        int temp = 0;
        for(int  j =  0 ;  j < (int)elements[i].size() ; ++j){
            if((elements[i][j]  >= 'A' && elements[i][j] <= 'Z') || (elements[i][j] >= 'a' && elements[i][j] <= 'z'))break;
            else {
                temp*=10;
                temp += elements[i][j] - 48;
            }
        }
        count.push_back(temp);
    }
    return count;
}
int countVowels(string x){
    int count = 0 ;
    for(int i =  0 ;  i < (int)x.size() ; ++i){
        if(x[i] == 'A' || x[i] == 'E' || x[i] == 'I' || x[i] == 'O' || x[i] == 'U' || x[i] == 'a' || x[i] == 'e' || x[i] == 'i' || x[i] == 'o' || x[i] == 'u'){
                count++;
        }
    }
    return count;
}
bool checkPrime(ll n){
    if(n == 1 || n == 0 )return false;
    for(int i = 2 ; i*i <= n ; ++i){
        if(n%i == 0)return false;
    }
    return true;
}
int main(){

    long long int n ;
    cin>>n;
    vector<string> elements;
    vector<string> emotions;
    vector<string> words(12);
    words[0] = "Zero";
    words[1] = "One" ;
    words[2] =  "Two" ;
    words[3] =  "Three" ;
    words[4] =  "Four";
    words[5] =  "Five" ;
    words[6] =  "Six" ; 
    words[7] = "Seven" ;
    words[8] =  "Eight" ;
    words[9] =  "Nine" ;
    words[10] = "Ten" ;
    words[11] =  "Eleven";
    for(int i = 0 ;  i < n ; ++i){
        string x;
        cin>>x;
        elements.push_back(x);
    }
    for(int i = 0 ;  i < n ; ++i){
        string y;
        cin>>y;
        emotions.push_back(y);
    }
    vector<ll> count(countElements(elements));
    unordered_map<string , ll> mp;
    mp["Happy"] = 10;
    mp["Sad"] = 5;
    mp["Neutral"] = 2;
    mp["None"] = 1;
    int bigScore  =  0 , smallScore = 0;
    for(int i = 0 ; i < n ; ++i){
        bigScore += (mp[emotions[i]]*count[i]);
    }

    for(int i = 0  ;  i < n ; ++i){
        smallScore += ((countVowels(elements[i])) * count[i]);
    }
    // cout<<bigScore << " " << smallScore<<endl;

    int areaScore = (bigScore/smallScore);
    checkPrime(areaScore)?cout<<"Yes":cout<<"No";
    cout<<" "<<words[areaScore];
    return 0;
}