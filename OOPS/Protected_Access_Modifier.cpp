#include<bits/stdc++.h>
using namespace std ;
class Person{
protected :
 string name ;
 public :
 void setName(string iname){
     name = iname ;
 }
};
class Student : public Person{
    public :
    void display(){
        cout<<name<<endl;
    }
};
int main(){
// Person bharat;
// bharat.name = " bharat";

Student bharat;
bharat.setName("Bharat Gupta");
bharat.display();
    return 0 ; 
}