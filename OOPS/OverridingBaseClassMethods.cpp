#include<iostream>
using namespace std ;
class Person{
public :
void introduce(){
    cout<<"Hey i am a person "<<endl;
}
};
class Student : public Person{
public:
void introduce(){
    cout<<"hey is am a Student "<<endl;
}
};
int main(){
Student bharat;
bharat.introduce();
    return 0 ; 
}