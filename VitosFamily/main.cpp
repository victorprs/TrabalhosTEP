#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sumDistance(vector<int> streets, int median)
{
    int total = 0;
    for (int i = 0; i < streets.size(); i++)
    {
        total += abs(median - streets[i]);
    }
    return total;
}

int main()
{
    int nCases;
    cin >> nCases;

    while (nCases--)
    {
        int relatives;
        cin >> relatives;

        vector<int> streets;
        int i = 0;
        while (relatives--)
        {
            int aux;
            cin >> aux;
            streets.push_back(aux);
        }

        sort(streets.begin(), streets.end());
        cout << sumDistance(streets, streets[streets.size()/2]) << endl;
    }
    return 0;
}
