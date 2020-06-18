#include <iostream>
using namespace std;
// constructors are generally used to initialise the members of the class
//constructors is called when a object is made
class Man
{
private:
    string name;
    int age;

public: /// we have to make the constructor public otherwise we will not able to access from outside the class
    Man()
    { // constructor do not have return type
        name = "no name ";
        age = -1;
        cout << "Constructor is called when you create object of the class " << endl;
    }
    Man(string iname)
    {
        name = iname;
        age = -1;
        cout << "Constructor with name as parameter " << endl;
    }
    Man(int iage)
    { 
        name = "no name ";
        age = iage;
        cout << "Constructor with age as parameter" << endl;
    }
    Man(string iname, int iage)
    { 
        name = iname;
        age = iage;
        cout << "Constructor with name and age as parameter" << endl;
    }
    void display(){
        cout<<name<<endl<<age<<endl;
    }
   
};
int main()
{
    Man bharat;
 bharat.display();
 cout<<"========================================="<<endl;
 Man shubham(14);
 shubham.display();
 cout<<"============================================="<<endl;
 Man gupta("BHarat Gupta");
 gupta.display();
 cout<<"==============================================="<<endl;
 Man saini("Shubham Saini",20);
 saini.display();
    return 0;
}