#include <bits/stdc++.h>
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define f(x, n) for (int x = 0; x < n; ++x)
int findPivot(int * a , int n ){
	        bool ithaspivot = false;
        for(int i = 0 ;  i < (sizeof(a)/sizeof(a[0])) - 1; ++i)
            if(!(a[i] <= a[i+1]))ithaspivot = true;
        if(!ithaspivot)return -1;
	int s = 0 , e = n-1;
int mid = s+ (e-s)/2;
while(s<e){
	if(a[mid] >= a[0])
	s = mid + 1;
	else e  =mid;
	mid = s+(e-s)/2;
}
return s;
}
int binarySearch(int * a , int n , int s , int e,int t){
	int mid = s + (e-s)/2;
    if(s == e)return a[e] == t ? e : -1;
	while(s<=e){
		if(t == a[mid])return mid;
		else if (t > a[mid])s= mid +1;
		else e = mid;
		mid = s + (e-s)/2;
	}
	return -1;
}
int main()
{
    fastio();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
int n ;
cin>>n;
int t;
cin>>t;
int a[n];
f(i,n)cin>>a[i];
// find pivot 
int pivot = findPivot(a,n);

cout<<pivot;
if(pivot == -1)cout<< binarySearch(a,n,0,n-1,t);
else if(a[pivot] <= t && t <= a[n-1])
cout<<binarySearch(a,n,pivot,n-1,t);
else cout<<binarySearch(a,n,0,pivot-1,t);

    return 0;
}