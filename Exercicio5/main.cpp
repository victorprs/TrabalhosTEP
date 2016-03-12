#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    string line1, line2;
    int nInputs;

    cin >> nInputs;

    for (int i = 0; i < nInputs; i++)
    {
        cin >> line1;
        cin >> line2;

        int moves = 0, swapZero = 0, swapOne = 0;
        int zero1 = 0, one1 = 0, zero2 = 0, one2 = 0, question = 0;

        for (int j = 0; j < line1.length(); j++)
        {
            if (line1[j] == line2[j])
                continue;
            if (line1[j] == '?')
                moves++;
            if (line1[j] == '0' && line2[j] == '1')
                swapZero++;
            if (line1[j] == '1' && line2[j] == '0')
                swapOne++;

            if (line1[j] == '1')
                one1++;
            else if (line1[j] == '0')
                zero1++;
            else
                question++;

            if (line2[j] == '1')
                one2++;
            else
                zero2++;
        }

        if (one1 > one2)
            cout << "Case " << i+1 << ": -1" << endl;
        else
        {
            if (swapZero > swapOne)
                moves += swapZero;
            else
                moves += swapOne;
            cout << "Case " << i+1 << ": " << moves << endl;
        }


    }

    return 0;
}
