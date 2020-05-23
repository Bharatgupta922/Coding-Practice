/* ----------------------------------------------------------------------------------------------------
RULES FOR CONVERTING INFIX EXPRESSION TO POSTFIX EXPRESSION 
1) Print the operands as they come. 
2)if stack is empty or contains a left paranthesis on top ,push the incoming operator on the stack .
3)if the incoming symbol is "(" ,push it onto the stack .
4)if incoming symbol is ")" ,pop the stack until left paranthesis .
5)if incoming symbol is higher precedence the top of the stack ,push it into the stack .
6)if the incoming symbol has lower precedence than the top of the stack ,pop & print the top .
Then test the incoming operator aggainst the new top of the stack .
7)if incoming operator has equal precedence with the top of the stack .
--> if associativity L to R then pop &print the top of the stack 
    & then push the incoming operator.
--> if associativity R to L then push the incoming operator .
8) At the end of the expression ,pop & print all the operators in the stack. 
---------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
string infixToPostFix(string y)
{
    stack<char> s;
    for (int i = 0; y[i] != '\0'; i++)
    {
        if (y[i] >= 65 && y[i] <= 90 || y[i] >= 97 && y[i] <= 122)
            cout << y[i];
        else
        {
            if (!s.empty() || y[i] == '(')
                s.push(y[i]);
           
        }
    }
}
int main()
{
    string y;
    cin >> y;
    y = infixToPostFix(y);
    cout << "the postfix expression is ---" << endl
         << y;
    return 0;
}
