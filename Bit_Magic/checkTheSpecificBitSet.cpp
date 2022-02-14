#include <iostream>
using namespace std;
int checkBit(int n, int pos)
{
    return (n & (1 << pos)) != 0;
}
int setBit(int n, int pos)
{
    return n | (1 << pos);
}
//or we can say clear bit
int unSetBit(int n, int pos)
{
    int mask = ~(1 << pos);
    return n & mask;
}
int updateBit(int n, int pos, int value)
{
    int mask = ~(1 << pos);
    n = n & mask;
    return n | (value << pos);
}
int main()
{
    // check bit is set or not
    cout << checkBit(5, 2) << endl;
    /// to set the bit at one position
    cout << setBit(5, 1) << endl;
    /// to set the bit at one position
    cout << unSetBit(5, 1) << endl;
    /// update bit with given bit
    cout << updateBit(5, 1, 1) << endl;

    return 0;
}