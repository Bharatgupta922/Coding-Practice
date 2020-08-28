#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	//code
	int t ;
	cin>>t;
	while(t--){
	    int n ;
	    cin>>n;
	    int first[n] ;
	    for(int i = 0; i < n ; ++i){
	       cin>>first[i];
	    }
	    int x ;cin>>x;
        int temp = first[x];

	    sort(first , first + n);

        for(int i = x ; i < n -1 ; ++i){
first[i+1] = first[i];
        }
        first[x] = temp;
	    for(int i = 0 ; i < n ; ++i){
	        cout<<first[i]<<" ";
	    }
        cout<<endl;
	}
	return 0;
}