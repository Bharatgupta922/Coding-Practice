#include <iostream>
using namespace std;
class Father
{
public:
    int height;
    void askFather()
    {
        cout << "i am your father ask me ,what do you want" << endl;
    }
};
class Mother
{
public:
    string skinColor;
    void askMother()
    {
        cout << "i am your mother ask me .what do you want" << endl;
    }
};
class Child : public Father, public Mother
{
public:
    void askParents()
    {
        cout << "i am asking my parents" << endl;
    }
    void setSkincolorAndHeight(string icolor, int iheight)
    {
        height = iheight;
        skinColor = icolor;
    }
    void display()
    {
        cout << "height is " << height << " and skin color is " << skinColor << "." << endl;
    }
};

int main()
{
Child bharat;
bharat.askFather();
bharat.askMother();
bharat.setSkincolorAndHeight("brown", 6);
bharat.display();
    return 0;
}