#include <iostream>
using namespace std;

class Marks
{
public:
    int marks;
    Marks()
    {
        this->marks = 0;
    }
    Marks(int marks)
    {
        this->marks = marks;
    }
    void yourMarks()
    {
        cout << "Your Marks is " << marks << endl;
    }

    //there is int argument to tell the compiler that operator is postfix
    Marks operator++(int)
    {
        //this duplicate object will save the marks to return on the current line
        //and after the line you will get the incremented one
        Marks duplicate(this->marks);
        marks += 1;
        return duplicate;
    }
    //there is int argument to tell the compiler that operator is postfix
    friend Marks operator--(Marks &currObj, int);
};

//there is int argument to tell the compiler that operator is postfix
Marks operator--(Marks &currObj, int)
{
    Marks duplicate(currObj.marks);
    currObj.marks -= 1;
    return duplicate;
}

int main()
{
    Marks bharatsMarks(68);
    int x = 20;
    (bharatsMarks++).yourMarks();
    (bharatsMarks--).yourMarks();
    return 0;
}