#include <iostream>
#include <vector>
#define VMAX 200

using namespace std;

int n, r, a, b;
vector<int> adjacencyMatrix[VMAX];
int visited[VMAX];

void dfs(int v) {
    visited[v] = 1;

    for (int w : adjacencyMatrix[v]) {
        if (!visited[w])
            dfs(w);
    }
}

int main()
{
    while (cin >> n) {
        cin >> r;

        for (int i = 0; i < n; i++) {
            adjacencyMatrix[i].clear();
            visited[i] = 0;
        }

        for (int i = 0; i < r; i++) {
            cin >> a >> b;
            adjacencyMatrix[a].push_back(b);
            adjacencyMatrix[b].push_back(a);
            visited[a]++;
            visited[b]++;
        }

        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] != 0) {
                if (visited[i] % 2 == 1) {
                    counter++;
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++)
            visited[i] = 0;

        if (counter || r < 2)
            cout << "Not Possible" << endl;
        else {
            dfs(0);
            bool flag = true;
            for (int i = 0; i < n; i++) {
                if (!visited[i])
                    flag = false;
            }
            if (flag)
                cout << "Possible" << endl;
            else
                cout << "Not Possible" << endl;
        }
    }
    return 0;
}
