#include<bits/stdc++.h>
using namespace std;
void PrintTheArray(int * a , int n){
    for(int i = 0 ;  i < n  ; ++i)
    cout<<a[i]<<" ,";
    cout<<endl;
}
void putRandom(int * a , int n ){
    for(int i = 0 ;  i < n ; ++i)
    a[i] = rand() % 100 + 1;
}
int Conquer(int * a , int startIndex, int mid , int endIndex,int * temp){
    int inversion=0;
    int i,j,k;
    i=startIndex;
    j=mid+1;
    k=startIndex;
    
    while((i<=mid)&&(j<=endIndex)){
        if(a[i]<=a[j])temp[k++]=a[i++];
        else {
            temp[k++]=a[j++];
            inversion += (mid-i);
        }
    }
    
    while(i<=mid)temp[k++]=a[i++];
    while(j<=endIndex)temp[k++]=a[j++];
    
    for(int i = startIndex ; i<= endIndex ; ++i)
        a[i] = temp[i];
        return inversion;
}
int Divide(int *a, int startIndex , int endIndex,int * temp){
    int inversion=0;
    if(startIndex < endIndex){
        int mid = startIndex + (endIndex-startIndex)/2;
        inversion += Divide(a,startIndex,mid,temp);
        inversion += Divide(a,mid+1,endIndex,temp);
        inversion += Conquer(a,startIndex,mid,endIndex,temp);
    }
    return inversion;
}
void mergeSort(int * a , int n,int * temp){
    cout<<Divide(a,0,n-1,temp)<<endl;
}
int main(){

    #ifndef ONLINE_MODE
       freopen("input.txt" , "r", stdin);
       freopen("output.txt","w",stdout); 
    #endif

    int a[5] = {0};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<"Normal Array ";
    putRandom(a,n);
    PrintTheArray(a,n);
    int temp[n];
    cout<<"Merge Sort ";
    mergeSort(a,n,temp);
    PrintTheArray(a,n);
    // int k;cin>>k;

    return 0;
}