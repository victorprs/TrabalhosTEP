#include <iostream>

using namespace std;

int main()
{
    int nInputs;
    cin >> nInputs;
    string inputs[nInputs];

    for (int i = 0; i < nInputs; i++)
    {
        cin >> inputs[i];
    }

    int totalScore;
    for (int i = 0; i < nInputs; i++)
    {
        totalScore = 0;
        int scoreCount = 0;
        for (int j = 0; j < (inputs[i].length()); j++)
        {
            if (inputs[i][j] == 'O')
                totalScore = totalScore + ++scoreCount;
            else
                scoreCount = 0;
        }
        cout << totalScore << endl;
    }

    return 0;
}
