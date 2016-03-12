#include <iostream>
#include <cmath>

using namespace std;

class Input
{
public:
    int poolLength;
    int poolDistance;
    int height;
    int initialVelocityX;
};

int main()
{
    int nInputs;

    cin >> nInputs;
    Input inputs[nInputs];

    for (int i = 0; i < nInputs; i++)
    {
        cin >> inputs[i].poolLength >> inputs[i].poolDistance >> inputs[i].height >> inputs[i].initialVelocityX;
    }

    for (int i = 0; i < nInputs; i++)
    {
        float finalX = inputs[i].initialVelocityX * sqrt(2*inputs[i].height/9800.0f);

        if (finalX < inputs[i].poolDistance - 500)
            cout << "FLOOR" << endl;
        else if (finalX < inputs[i].poolDistance + 500)
            cout << "EDGE" << endl;
        else if (finalX < inputs[i].poolDistance + inputs[i].poolLength - 500)
            cout << "POOL" << endl;
        else if (finalX < inputs[i].poolDistance + inputs[i].poolLength + 500)
            cout << "EDGE" << endl;
        else
            cout << "FLOOR" << endl;
    }

    return 0;
}
