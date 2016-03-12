#include <iostream>
#include <vector>
#include <queue>
#define VMAX 100
#define INF 2147483647

using namespace std;

int n, m, s, d;
vector<int> adjacencyMatrix[VMAX];
int dist[VMAX], visited[VMAX];

void bfs(int root) {
    queue<int> fila;

    fila.push(root);

    while (!fila.empty()) {
        int v = fila.front();
        fila.pop();

        visited[v] = 1;

        for (int w : adjacencyMatrix[v]) {
            if (!visited[w]) {
                visited[w] = 1;
                dist[w] = dist[v] + 1;
                fila.push(w);
            }
        }
    }
}

int main()
{
    int nInputs;
    cin >> nInputs;
    for (int nCase = 1; nCase <= nInputs; nCase++) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adjacencyMatrix[a].push_back(b);
            adjacencyMatrix[b].push_back(a);
        }
        cin >> s >> d;

        int d1[VMAX];
        for (int i = 0; i < VMAX; i++) {
            d1[i] = 0;
            dist[i] = 0;
            visited[i] = 0;
        }

        bfs(s);

        for (int i = 0; i < n; i++)
            d1[i] = dist[i];


        for (int i = 0; i < VMAX; i++) {
            dist[i] = 0;
            visited[i] = 0;
        }

        bfs(d);
        int maxSoma = 0;
        for (int i = 0; i < n; i++) {
            if (d1[i] + dist[i] > maxSoma)
                maxSoma = d1[i] + dist[i];
        }

        cout << "Case " << nCase << ": " << maxSoma << endl;

        for (int i = 0; i < VMAX; i++) {
            adjacencyMatrix[i].clear();
        }
    }
    return 0;
}
