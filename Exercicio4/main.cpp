#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

static const float C_ATOMIC_WEIGH = 12.01f;
static const float H_ATOMIC_WEIGH = 1.008f;
static const float O_ATOMIC_WEIGH = 16.00f;
static const float N_ATOMIC_WEIGH = 14.01f;

int nextElementAt(string molecule, int curPos)
{
    for (int i = curPos + 1; i < molecule.length(); i++)
    {
        if (molecule[i] == 'C' || molecule[i] == 'H' || molecule[i] == 'O' || molecule[i] == 'N')
            return i;
    }
    return -1;
}

int identifyQtdElement(string molecule, int curPos)
{
    string qtd = "";
    for (int i = curPos + 1; i < molecule.length(); i++)
    {
        if (molecule[i] == 'C' || molecule[i] == 'H' || molecule[i] == 'O' || molecule[i] == 'N')
            break;
        qtd.append(molecule, i, 1);
    }
    if (qtd.empty())
        return 1;
    else
        return atoi(qtd.c_str());
}

float getAtomicWeight(char element, int curPos)
{
    switch(element) {
        case 'C':
            return C_ATOMIC_WEIGH;
        case 'H':
            return H_ATOMIC_WEIGH;
        case 'O':
            return O_ATOMIC_WEIGH;
        case 'N':
            return N_ATOMIC_WEIGH;
    }
}

int main()
{
    int nInputs;
    cin >> nInputs;
    string inputs[nInputs];

    for (int i = 0; i < nInputs; i++)
    {
        cin >> inputs[i];
    }

    for (int i = 0; i < nInputs; i++)
    {
        float molarMass = 0.0f;
        int j = 0;
        while (j < inputs[i].length())
        {
            int nxtElementPos = nextElementAt(inputs[i], j);
            int curQtdElement = identifyQtdElement(inputs[i], j);
            float curElementAtomicW = getAtomicWeight(inputs[i][j], j);
            molarMass += curElementAtomicW * curQtdElement;
            if (nxtElementPos == -1)
                break;
            j = nxtElementPos;
        }
        cout << fixed << setprecision(3) << molarMass << endl;
    }

    return 0;
}
