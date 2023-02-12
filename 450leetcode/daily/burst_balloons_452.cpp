#include <bits/stdc++.h>
using namespace std;
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 1)return 1;
        vector<pair<int,int> >arr;
        for(int i = 0 ;  i < points.size(); ++i)
            arr.push_back({points[i][0],points[i][1]});
        sort(arr.begin(),arr.end());
        int l = arr[0].first, h = arr[0].second;
        int count = 0 ;
        for(int i = 1  ; i < arr.size() ; ++i){
            if(h < arr[i].first ){
                count++;
								cout<<"heres is the h"<<h<<"which compared to l"<<arr[i].first<<endl;
                h = arr[i].second;
            }
						if(i == arr.size()-1 && h != arr[i].second)
						count++;
        }
        return count == 0? 1 : count;
    }
int main()
{
    // 6
    // 3 2 6 5 0 3

    #ifndef ONLINE_MODE
       freopen("input.txt" , "r", stdin);
       freopen("output.txt","w",stdout);
    #endif
int n ;
cin>>n;
vector<vector<int> > v;
for(int i = 0 ;  i< n ; ++i){
	vector<int> temp;
	int x,y;
cin>>x>>y;
temp.push_back(x);
temp.push_back(y);
v.push_back(temp);
}
cout<<findMinArrowShots(v)<<endl;


    return 0;
}
