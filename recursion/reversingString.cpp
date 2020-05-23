#include<iostream>
#include<string>
using namespace std ;
void reverse(string s){
    if(s.size() == 0)return ;
    reverse(s.substr(1));
    cout<<s[0];
}
int main(){

string s = "Bharat gupta";
reverse(s);
    return 0;
}