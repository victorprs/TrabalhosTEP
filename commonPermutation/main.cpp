#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    while (true)
    {
        string a, b;
        if (!getline(cin, a) || !getline(cin, b))
            break;

        string result = "";
        bool isOnLetters[26] = {false};
        for (string::iterator it = a.begin(); it != a.end(); it++)
        {
            if (!isalpha(*it)) continue;
            int found = b.find(*it);
            if (found != string::npos)
            {
                result += *it;
                b[found] = '.';
            }
        }

        sort(result.begin(), result.end());

        cout << result << endl;
    }
    return 0;
}
