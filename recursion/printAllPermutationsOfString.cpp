#include<iostream>
#include<string>
#include<set>
using namespace std;
string interchange(char * s , int a , int b){
char temp = s[a];
s[a] =s[b];
s[b] = temp;
return s;
}
void permutations(string s , int l , int r , set<string> &hash){
    if(l == r){
        hash.insert(s);
        return ;
    }
    for(int i = l ; i<=r ; ++i){
        s = interchange(&s[0],l,i);
      permutations(s,l+1,r,hash);
      s = interchange(&s[0],l,i); // BackTrack for next iteration 
    }
}
int main(){
    set<string> hash;
    permutations("abc",0,2,hash);
    for(set<string>::iterator it = hash.begin() ; it!=hash.end() ; ++it){
        cout<<*it<<"\n";
    }
    return 0;
}