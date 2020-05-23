#include<iostream>
#include<string>
using namespace std ;
int countConsonants(char * s , int i , int count){
if(!s[i])return count;
s[i] = toupper(s[i]);
if(!(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'))count++;
return countConsonants(s,++i,count);
}

int main(){
 char s[15]= "geeksForGeeks";
cout<<countConsonants(s,0,0);
    return 0;
}