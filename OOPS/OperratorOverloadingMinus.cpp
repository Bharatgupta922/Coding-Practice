#include <iostream>
using namespace std;
// like a=  10 , b = 20
// if we want to implement any mathematical operation
// you need todo write a+b, a-b ,a*b , a/d
// but can we do it with custom objects that we create in our program ?
// no , we can't b/c these operators are not designed to wrok with our
// customly build objects

// but if we want to do that c++ offers one of the powerful features i.e operator overloading
// operator overloading is nothing but making the operators to work with customly built objects
// and none of the properties of overloaded is deprive after overloading insted it will expand
class Marks
{
    int intmark; // // by default private
    int extmark;

public:
    Marks()
    { // default constructor
        intmark = 0;
        extmark = 0;
    }
    Marks(int intmark, int extmark)
    {
        this->intmark = intmark;
        this->extmark = extmark;
    }
    void display()
    {
        cout << this->intmark << endl
             << this->extmark << endl;
    }

    /// operator overloading

    // syntax :
    // return-type operator+ (parameters of same class ){
    // make new object

    // do operations and assign to the new object
    // then
    // return new object or current object
    // }

    Marks operator+(Marks m)
    {
        Marks temp;
        temp.intmark = intmark + m.intmark;
        temp.extmark = extmark + m.extmark;
        return temp;
    }
    // when we defining the operator overloading as a member function
    // of the class the first parameter is by default  passed as current object
    //so we just need to pass the define one argument

    Marks operator-(Marks m);
    // operator declaration
};

//defining the operator overloading outside the class

// syntax :
// return-type name-of-class :: operator- (parameters of same class ){
// make new object

// do operations and assign to the new object
// then
// return new object or current object
// }

Marks Marks ::operator-(Marks m)
{
    Marks temp;
    temp.intmark = intmark - m.intmark;
    temp.extmark = extmark - m.extmark;
    return temp;
}
int main()
{
    Marks m1(10, 20);
    Marks m2(30, 40);
    //here now you can use + with objects of Marks i.e after overloading
    Marks m3 = m1 + m2;
    Marks m4 = m1 - m2;
    m3.display();
    m4.display();
    return 0;
}