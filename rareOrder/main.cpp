#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string line;
    getline(cin, line);

    vector<string> inputs;
    char alphabet[26] = {0};
    vector<int> lengths;

    while (line != "#")
    {
        inputs.insert(inputs.end(), line);
        lengths.insert(lengths.end(), line.length());
        getline(cin, line);
    }

    int k = 0;
    for (int j = 0; j < lengths[k]; j++)
    {
        for (int i = 0; i < inputs.size(); i++)
        {
            if (inputs[i][j] > 64 && inputs[i][j] < 91)
                alphabet[(inputs[i][j] - 65)]++;
            if (alphabet[(inputs[i][j] - 65)] == 1)
                cout << inputs[i][j];
        }
        k++;
    }

    cout << endl;

    return 0;
}
