#include <bits/stdc++.h>
using namespace std;

///base class or parent class
class Person
{
public:
    string name;
    int age;
    void setName(string iname)
    {
        name = iname;
    }
    void setAge(int iage)
    {
        age = iage;
    }
};

//subclass or child class 
class Student : public Person{
    public :
    int id ;
    void setID(int iID){
        id = iID;
    }
    void introduce(){
        cout<<"hi i am "<<name<<" and i am "<<age<<" years old with id "<<id;
    }
};
int main()
{
    Student bharat ;
    bharat.setName("Bharat Gupta");
    bharat.setAge(18);
    bharat.setID(1910990384);
    bharat.introduce();
    return 0 ;
}