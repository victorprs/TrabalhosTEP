#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

int main()
{
    int nInputs;
    string input;
    getline(cin, input);
    nInputs = atoi(input.c_str());

    string inputs[nInputs];

    for (int i = 0; i < nInputs; i++)
    {
        getline(cin, inputs[i]);
    }

    for (int i = 0; i < nInputs; i++)
    {
        int parenthesisCount = 0;
        int bracketsCount = 0;
        stack<char> st;
        bool correct = true;
        for (int j = 0; j < inputs[i].length(); j++)
        {
            if (inputs[i][j] == '(' || inputs[i][j] == '[')
                st.push(inputs[i][j]);
            else if (inputs[i][j] == ')' && !st.empty() && st.top() == '(')
                st.pop();
            else if (inputs[i][j] == ']' && !st.empty() && st.top() == '[')
                st.pop();
            else
                correct = false;
        }

        if (st.empty() && correct)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
