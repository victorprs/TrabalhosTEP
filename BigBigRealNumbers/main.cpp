#include <iostream>

using namespace std;

class BigInt
{
    public:
    BigInt(string str):
        number(str) {}
    string number;

    BigInt operator+(BigInt n2)
    {
        bool n2Bigger = n2.number.length() > this->number.length();

        int biggestLength;
        string n1str, n2str;

        if (n2Bigger)
        {
            n1str = string(n2.number.length() - this->number.length(),
                                   '0') + this->number;
            biggestLength = n2.number.length();
            n2str = n2.number;
        }
        else
        {
            n2str = string(this->number.length() - n2.number.length(),
                                   '0') + n2.number;
            biggestLength = this->number.length();
            n1str = this->number;
        }

        int carry[biggestLength + 1];
        for (int i = 0; i < biggestLength; i++)
            carry[i] = 0;


        string result = "";
        for (int i = biggestLength - 1; i > -1 ; i--)
        {
            int aux = n1str[i] - 48 + n2str[i] - 48;

            if (i != biggestLength - 1)
            {
                aux += carry[i + 1];
            }

            result.insert(result.begin(), aux % 10 + 48);
        }

        return BigInt(result);
    }

};

int main()
{
    int nInputs;
    cin >> nInputs;
    while (nInputs--)
    {
        string a, b;
        cin >> a, b;
    }

    return 0;
}
