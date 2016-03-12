#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#define MAX_K 100
using namespace std;

int m;
float price;
string input;

int toint(string s) {
    return atoi(s.c_str());
}

int main()
{
    int nCase = 1;
    while (cin >> price >> m) {
        int n[m];
        float p[m];
        for (int i = 0; i < m; i++) {
            cin >> n[i] >> p[i];
        }

        float dp[MAX_K + 1] = {0};
        for (int i = 1; i <= MAX_K; i++)
            dp[i] = price * i;
        for (int i = 0; i < m; i++) {
            for (int k = 0; k <= MAX_K - n[i]; k++)
                for (int a = 1; a <= n[i]; a++)
                    dp[k + a] = min(dp[k + a], dp[k] + p[i]);

        }

        cin.ignore(256, '\n');
        getline(cin, input);
        stringstream sstream(input);
        int nItems;
        string item;
        cout << "Case " << nCase++ << ":" << endl;
        while (getline(sstream, item, ' ')) {
            nItems = toint(item);

            cout.precision(2);
            cout << "Buy " << nItems << " for $" << std::fixed << dp[nItems] << endl;
        }
    }

    return 0;
}
