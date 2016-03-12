#include <iostream>
#include <sstream>

using namespace std;

int getCarryOperations(unsigned int a, unsigned int b)
{
    stringstream astream, bstream;
    astream << a;
    int lengthA, lengthB;
    lengthA = astream.str().length();

    bstream << b;
    lengthB = bstream.str().length();

    bool isABigger = lengthA > lengthB;
    int cLength = isABigger? lengthA: lengthB;

    int carry[cLength];

    for (int i = 0; i < cLength; i++)
        carry[i] = 0;

    string aStr, bStr;
    if (isABigger)
    {
        aStr = astream.str();
        bStr = string(lengthA - lengthB, '0') + bstream.str();
    }
    else
    {
        bStr = bstream.str();
        aStr = string(lengthB - lengthA, '0') + astream.str();
    }
    for (int i = 1; i < cLength + 1; i++)
    {
        int aux = aStr.at(aStr.length() - i) - 48 + bStr.at(bStr.length() - i) - 48;
        if (i != 1)
        {
            aux += carry[cLength - i + 1];
        }
        if (aux > 9)
            carry[cLength - i] = 1;
    }

    int result = 0;
    for (int i = 0; i < cLength; i++)
        result += carry[i];

    return result;
}

int main()
{
    while (true)
    {
        unsigned int a, b;
        cin >> a >> b;

        if (a == 0 && b == 0)
            break;

        int carry = getCarryOperations(a, b);

        if (carry == 0)
            cout << "No carry operation." << endl;
        else if (carry == 1)
            cout << "1 carry operation." << endl;
        else
            cout << carry << " carry operations." << endl;
    }

    return 0;
}
