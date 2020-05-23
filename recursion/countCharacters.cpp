#include<iostream>
using namespace std ;
int countChar(char * s , int i ){
    if(!s[i])return 0;
    return 1+countChar(s,++i);
}
int main(){
    char s[50] = "Geeks for Geeks";
    cout<<countChar(s,0);
    return 0;
}