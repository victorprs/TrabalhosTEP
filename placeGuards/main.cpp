#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#define VMAX 200

using namespace std;

int v, e, p1, p2, answer;
int visited[VMAX], partitions[VMAX];
vector<int> adjacencyMatrix[VMAX];

bool bfs(int root) {
    queue<int> qu;
    qu.push(root);
    visited[root] = 1;
    partitions[root] = 1;
    p1 = 0; p2 = 0;
    p1++;

    while (!qu.empty()) {
        int v = qu.front();
        qu.pop();
        for (int w : adjacencyMatrix[v]) {
            if (partitions[w] == partitions[v])
                return false;
            if (visited[w] == 0) {
                visited[w] = 1;
                if (partitions[v] == 1) {
                    p2++;
                    partitions[w] = 2;
                }
                else {
                    p1++;
                    partitions[w] = 1;
                }
                qu.push(w);
            }
        }
    }
    return true;
}


bool bipartite() {
    for (int i = 0; i < v; i++) {
        if (visited[i] == 0){
            bool isBipartite = bfs(i);
            if (!isBipartite)
                return false;
            else
                answer += (p1 > 0 && p2 > 0)? min(p1, p2): max(p1, p2);
        }
    }
    return true;
}

int main()
{
    int nInputs;
    cin >> nInputs;
    vector<int> respostas;
    while (nInputs--) {
        cin >> v >> e;
        p1 = 0; p2 = 0; answer = 0;
        memset(visited, 0, VMAX);
        memset(partitions, 0, VMAX);

        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            adjacencyMatrix[a].push_back(b);
            adjacencyMatrix[b].push_back(a);
        }

        if (bipartite())
            cout << answer << endl;

        else
            cout << -1 << endl;

        for (int i = 0; i < VMAX; i++)
            adjacencyMatrix[i].clear();
    }
    return 0;
}
