#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std ;
int main(){
    //  int a[] = {2,-1,3,4,2};
    //  bool found = false ;
    // unordered_set <int> s ;
    //  int sum = 0;
    //  for(int i = 0;i<5;i++){
    //      s.insert(sum);
    //      sum += a[i];
    //      if(s.find(sum)!=s.end()){
    //          found = true;
    //          break;
    //      }
    //  }
    //  if(found)cout<<"Found";
    //  else cout<<"Not Found";
     
     
    //     int a[] = {2,-1,3,4,2};
    //  bool found = false ;
    // unordered_set <int> s ;
    //  int sum = 0,k = 3;
    //  for(int i = 0;i<5;i++){
    //      s.insert(sum);
    //      sum += a[i];
    //      if(s.find(sum-k)!=s.end()){
    //          found = true;
    //          break;
    //      }
    //  }
    //  if(found)cout<<"Found";
    //  else cout<<"Not Found";

    
        int a[] = {2,-1,3,4,2};
     bool found = false ;
    unordered_map <int , int> m ;
     int sum = 0,k = 3 , count  = 0 ;
     for(int i = 0;i<5;i++){
         sum += a[i];
         m[sum] = i;
         if(sum == k){
             cout<<"range is 0 to "<<i<<endl;
             found = true ;
             break;
         }
         if(m.find(sum-k)!=m.end()){
             cout<<"range is "<<m[sum-k]+1<<" to "<<i<<endl;
             found = true;
             break;
         }
     }
     if(!found)cout<<"Not found !"<<endl;
    return 0;
}
