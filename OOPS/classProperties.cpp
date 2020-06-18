#include<iostream>
using namespace std ;
class Man{
    public:    //access specifiers 
    string name ;
    void introduce(){
        cout<<"hi , My name is "<<name<<endl;
    }
};
int main(){
    Man bharat , shubham ;
    bharat.name = "Bharat Gupta";
    shubham.name = "Shubham Saini";
    bharat.introduce();
    shubham.introduce();
}