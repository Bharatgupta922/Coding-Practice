#include <bits/stdc++.h>

using namespace std;

class Student{
  public:
  string id;
  double percntg;
  string chi;
  string chii;
  string chiii;
  
  bool operator > (const Student& st) const
    {
        return (percntg > st.percntg);
    }
    
  int choicetoint(string st){
       
      st.replace(0, 2, "");
      return atoi(st.c_str());
  }
};

int main()
{
   int stdnts;
   int collegs;
   
   std::vector<int> seats;
   vector<Student> sts;
   cin>>collegs>>stdnts;
   for(int i=0;i<collegs;i++){
       int seat;
       cin>>seat;
       seats.push_back(seat);
   }
   
   for(int i=0;i<stdnts;i++){
   Student s;
   string in;
   cin>>in;
   string w = "";
   vector<string> tmp;
   for(auto x : in) 
    {
        if (x == ',')
        {
           tmp.push_back(w);
            w = "";
        }
        else {
            w = w + x;
        }
    }
    tmp.push_back(w);
   s.id=tmp[0];
   s.percntg=stod(tmp[1]);
   s.chi=tmp[2];
   s.chii=tmp[3];
   s.chiii=tmp[4];
   sts.push_back(s);
   }
   
   sort(sts.begin(),sts.end(),greater<Student>());
//   cout<<endl<<endl;
// for(int i=0;i<stdnts;i++){
//   Student s=sts[i];
//   cout<<s.id << " "<<s.percntg<<" "<<s.chi<<" "<<s.chii<<" "<<s.chiii<<endl;
//   }
   
   vector<pair<string,string>> rslt;
   int ptr=0;
   for(int i=0;i<stdnts;i++){
       Student s=sts[i];
       int a=s.choicetoint(s.chi);
       int b=s.choicetoint(s.chii);
       int c=s.choicetoint(s.chiii);
       if(seats[a-1]>0){
           seats[a-1]--;
           rslt.push_back({s.id,s.chi});
         
       }
       else{
        if(seats[b-1]>0){
           seats[b-1]--;
           rslt.push_back({s.id,s.chii});
          
       }
       else{
        if(seats[c-1]>0){
           seats[c-1]--;
           rslt.push_back({s.id,s.chiii});
           
       }
       }
       }
       
   }
   for(int i=0;i<(int)rslt.size();i++){
   
   cout<<rslt[i].first<< " "<<rslt[i].second<<endl;
  }
    return 0;
}