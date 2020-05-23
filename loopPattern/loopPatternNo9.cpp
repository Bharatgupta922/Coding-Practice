/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    int n ;
    cin>>n;
for(int i =1;i<=n;i++){
for(int j=1;j<=n-i;j++)
cout<<"  ";
for(int j=1;j<=i;j++)
cout<<"* ";
cout<<endl;
}
for(int i =1;i<=n-1;i++){
    for(int j =1;j<=i;j++)
    cout<<"  ";
    for(int j =1;j<=n-i;j++)
    cout<<"* ";
    cout<<endl;
}
    return 0;
}

