#include<iostream>
using namespace std ;
void floodFill(int a[8][8],int tofill , int r ,int c , int prefill , int x ,int y){
    if(r<0 || r>=x || c<0 || c>=y)return ;
    if(a[r][c] != prefill || a[r][c] == tofill)return ;
    a[r][c] = tofill;
    floodFill(a,tofill,r-1,c,prefill,x,y);
    floodFill(a,tofill,r,c-1,prefill,x,y);
    floodFill(a,tofill,r,c+1,prefill,x,y);
    floodFill(a,tofill,r+1,c,prefill,x,y);
}
void printMat(int a[8][8] , int x , int y ){
    for(int i=0;i<x;++i){
        for(int j = 0 ; j < y ; ++j){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){

int a[][8]= {
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,0},
    {1,0,0,1,1,0,1,1},
    {1,2,2,2,2,0,1,0},
    {1,1,1,2,2,0,1,0},
    {1,1,1,2,2,2,2,0},
    {1,1,1,1,1,2,1,1},
    {1,1,1,1,1,2,2,1}};
floodFill(a,3,3,1,2,8,8);
printMat(a,8,8);

}