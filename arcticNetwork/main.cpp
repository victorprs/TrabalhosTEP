#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <functional>
#include <cstring>
#include <algorithm>
#define VMAX 501
#define INF 2147483647
#define coord pair<double, double>

using namespace std;

int sats, n;
vector<int> adjacencyList[VMAX];
double distances[VMAX][VMAX];
double d;

class CompareEdge {
public:
    bool operator()(coord const& a, coord const& b) const {
        return a.second > b.second;
    }
};

double distance(coord o, coord p) {
    return sqrt(pow(o.first - p.first, 2) + pow(o.second - p.second, 2));
}

void prim() {
    priority_queue<coord, vector<coord>, CompareEdge> fila;

    double q[n], treeDist[n-1];
    int s[n];

    for (int i = 0; i < n; i++) {
        q[i] = (i==0?0:INF);
        s[i] = 0;
        fila.push(make_pair(i, q[i]));
    }

    int exploredNodes = 0;

    int v;
    while (exploredNodes < n) {
        v = fila.top().first;
        fila.pop();

        if (s[v] == 1)
            continue;
        s[v] = 1;
        exploredNodes++;

        if (v != 0)
            treeDist[v-1] = q[v];

        for (int w : adjacencyList[v]) {
            if (distances[v][w] < q[w]) {
                q[w] = distances[v][w];
                fila.push(make_pair(w, q[w]));
            }
        }
    }

    sort(treeDist, treeDist + (n-1));
    d = treeDist[(n-2)-(sats-1)];
}

int main()
{
    int nInputs;
    cin >> nInputs;
    while (nInputs--) {
        cin >> sats >> n;
        coord coords[n];
        for (int i = 0; i < n; i++) {
            cin >> coords[i].first >> coords[i].second;
        }

        d = 0;
        memset(distances, 0, VMAX*VMAX);
        for (int i = 0; i < VMAX; i++)
            adjacencyList[i].clear();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    distances[i][j] = distance(coords[i], coords[j]);
                    distances[j][i] = distance(coords[i], coords[j]);
                    adjacencyList[i].push_back(j);
                    adjacencyList[j].push_back(i);
                }
                else {
                    distances[i][j] = 0;
                }
            }
        }

        prim();

        cout.precision(2);
        cout << fixed << d << endl;
    }
    return 0;
}
