#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

string str;
int strLen;

vector<string> permutations;

void bsearch(array<int, 128> permSoFar, string perm, int n) {
    if (n == strLen) {
        permutations.insert(permutations.end(), perm);
        return;
    }

    bool charsUsed[128] = {false};

    for (int i = 0; i < strLen; i++) {
        char c = str[i];

        if (charsUsed[c] == 0 && permSoFar[c] != 0) {
            charsUsed[c] = 1;
            permSoFar[c]--;
            bsearch(permSoFar, perm + c, n+1);
            permSoFar[c]++;
        }
    }
}

int main()
{
    int nInputs;


    cin >> nInputs;
    while (nInputs--) {
        cin >> str;
        strLen = str.length();

        sort(str.begin(), str.end());

        array <int, 128> permSoFar = {0};
        for (int i = 0; i < strLen; i++) {
            permSoFar[str[i]]++;
        }

        bsearch(permSoFar, "", 0);

        for (vector<string>::iterator it = permutations.begin(); it != permutations.end(); it++)
            cout << *it << endl;
        cout << endl;

        permutations.clear();

    }
    return 0;
}
