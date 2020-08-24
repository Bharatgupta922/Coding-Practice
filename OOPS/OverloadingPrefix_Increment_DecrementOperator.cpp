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
    Marks operator++()
    {
        this->marks = this->marks - 1;
        return *this;
    }
    friend Marks operator--(Marks &currObj);
};

Marks operator--(Marks &currObj)
{
    currObj.marks = currObj.marks - 1;
    return currObj;
}

int main()
{
    Marks bharatsMarks(68);
    int x = 20;
    (++bharatsMarks).yourMarks();
    (--bharatsMarks).yourMarks();   
    return 0;
}