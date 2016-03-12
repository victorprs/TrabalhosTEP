#include <iostream>
#include <limits>
#include <queue>
#define MAX_N 100

using namespace std;

int n, s, t, c;
int graph[MAX_N][MAX_N], residual[MAX_N][MAX_N];

bool bfs(int pi[]) {
    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    pi[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            if (!visited[v] && residual[u][v] > 0) {
                q.push(v);
                pi[v] = u;
                visited[v] = 1;
            }
        }
    }

    return visited[t];
}

int bandwith() {
    int u, v;

    for (u = 0; u < n; u++)
        for (v = 0; v < n; v++)
            residual[u][v] = graph[u][v];

    int pi[n];
    int maxFlow = 0;

    while (bfs(pi)) {
        int pathFlow = std::numeric_limits<int>::max();
        for (v = t; v != s; v = pi[v]) {
            u = pi[v];
            pathFlow = min(pathFlow, residual[u][v]);
        }

        for (v = t; v != s; v = pi[v]) {
            u = pi[v];
            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main()
{
    int nTestCase = 0;
    cin >> n;
    while (n) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                graph[i][j] = 0;

        cin >> s >> t >> c;
        s--;t--;
        for (int i = 0; i < c; i++){
            int u, v, f;
            cin >> u >> v >> f;
            u--;v--;

            graph[u][v] += f;
            graph[v][u] += f;
        }

        cout << "Network " << ++nTestCase << endl;
        cout << "The bandwidth is " << bandwith() << '.' << endl << endl;

        cin >> n;
    }

    return 0;
}
