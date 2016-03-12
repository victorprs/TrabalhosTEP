#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m, c, k;
int dp[201][21];
vector<int> g[20];

int main()
{
    cin >> n;
    while (n--) {
        cin >> m >> c;
        for (int i = 0; i < c; i++) {
            cin >> k;
            g[i].resize(k);
            for (int j = 0; j < k; j++)
                cin >> g[i][j];
        }

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= c; j++){
                dp[i][j] = -2;
            }
        }

        for (int i = 0; i <= m; i++){
            dp[i][0] = 0;
            for (int j = 1; j <= c; j++) {
                for (int l = 0; l < g[j-1].size(); l++) {
                    int ci = g[j-1][l];
                    if (i >= ci && dp[i-ci][j-1] != -2)
                        dp[i][j] = max(dp[i][j], dp[i-ci][j-1] + ci);
                }
            }
        }

        if (dp[m][c] == -2)
            cout << "no solution" << endl;
        else
            cout << dp[m][c] << endl;
    }
    return 0;
}
