#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <unordered_map>
#include <cstring>
#include <functional>
#define INF 2147483647
#define VMAX 20000
#define EMAX 50000
#define par pair<int, int>

using namespace std;

int n, m, s, t;
int distances[VMAX][VMAX];
vector<int> adjacencyList[VMAX];

class CompareEdge {
public:
    bool operator()(par const& a, par const& b) const {
        return a.second > b.second;
    }
};

struct pairhash {
public:
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U> &x) const {
        return 3 * std::hash<T>()(x.first) + std::hash<U>()(x.second);
    }
};

int dijkstra() {
    priority_queue<par, vector<par>, CompareEdge> pq;

    int dist[n], status[n];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        status[i] = 0;
    }
    dist[s] = 0;

    pq.push(par(s, dist[s]));

    while (!pq.empty()) {
        par v = pq.top();
        pq.pop();
        status[v.first] = 1;

        for (int w : adjacencyList[v.first]) {
            if (dist[w] > dist[v.first] + distances[v.first][w]){
                dist[w] = dist[v.first] + distances[v.first][w];
                if (status[w] == 0) {
                    pq.push(par(w, dist[w]));
                }
            }
        }
    }

    if (dist[t] == INF)
        return -1;
    return dist[t];
}

int main()
{
    int nInputs;
    cin >> nInputs;
    for (int nCase = 1; nCase <= nInputs; nCase++) {
        cin >> n >> m >> s >> t;

        for (int i = 0; i < n; i++)
            adjacencyList[i].clear();

        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;

            distances[a][b] = c;
            distances[b][a] = c;
            adjacencyList[a].push_back(b);
            adjacencyList[b].push_back(a);
        }

        int d = dijkstra();
        if (d == -1)
            cout << "Case #" << nCase << ": unreachable" << endl;
        else
            cout << "Case #" << nCase << ": " << d << endl;

    }
    return 0;
}
