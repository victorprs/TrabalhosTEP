#include <iostream>

using namespace std;
//
//unsigned long long int maxPieces(int n)
//{
//    return;
//}

class BigInt
{
public:
    BigInt(){}
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
        for (int i = 0; i < biggestLength + 1; i++)
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
            carry[i] = aux / 10;
        }

        if (carry[0] != 0)
            result.insert(result.begin(), carry[0] + 48);

        return BigInt(result);
    }

    BigInt operator*(BigInt n2)
    {

        bool n2Bigger = n2.number.length() > this->number.length();

        int smallerLength, biggerLength;
        string bigN, smallN;

        if (n2Bigger)
        {
            smallerLength = this->number.length();
            biggerLength = n2.number.length();
            bigN = n2.number;
            smallN = this->number;
        }
        else
        {
            smallerLength = n2.number.length();
            biggerLength = this->number.length();
            bigN = this->number;
            smallN = n2.number;
        }

        BigInt addNumbers[smallerLength];

        int carry[biggerLength + 1];

        for (int i = smallerLength - 1, k = 0; i > -1; i--, k++)
        {
            for (int j = 0; j < biggerLength + 1; j++)
                carry[j] = 0;

            string n;
            for (int j = biggerLength - 1; j > -1; j--)
            {
                int aux = (smallN[i] - 48) * (bigN[j] - 48);
                if (j != biggerLength - 1)
                {
                    aux += carry[j + 1];
                }

                n.insert(n.begin(), aux % 10 + 48);
                carry[j] = aux / 10;
            }

            if (carry[0] != 0)
                n.insert(n.begin(), carry[0] + 48);

            n.append(string(k,'0'));

            addNumbers[k] = BigInt(n);

        }

        BigInt result("0");

        for (int i = 0; i < smallerLength; i++)
            result = result + addNumbers[i];

        return result;
    }

    BigInt operator-(BigInt n2)
    {

    }
};

int combination(int n, int r)
{
    int result = 1;

    for (int i = n; i > n-r; i--)
    {
        result = result * i;
    }

    int underN = 1;
    for (int i = r; i > 0; i--)
    {
        underN = underN * i;
    }

    return result/underN;
}

int main()
{
//    int nInputs;
//    cin >> nInputs;
//
//    while (nInputs--)
//    {
//        unsigned int n;
//        cin >> n;
//
//        //cout << maxPieces(n) << endl;
//    }

    while (true)
    {
//        string input;
//        cin >> input;
//        BigInt a(input);
//        cin >> input;
//        BigInt b(input);

        int n, r;
        cin >> n >> r;

        cout << combination(n, r) << endl;

        //BigInt c = a + b;
        //BigInt d = a * b;
        //cout << c.number << endl;
        //cout << d.number << endl;
    }


    return 0;
}
