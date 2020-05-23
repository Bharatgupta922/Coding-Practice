#include<stdio.h>
void swap(int *a,int *b ){
int temp = *a;
*a= *b;
*b = temp;
}
void partition (int a[],int n ,int x){
int i = 0,j = n-1;

}
int main(){
    int a [10] = {28,26,25,11,16,12,24,29,6,10};
    partition(a,10,17);
    for(int i=0;i<10;i++)printf("%d\n",a[i]);
}