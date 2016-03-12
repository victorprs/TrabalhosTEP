#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <functional>
#include <cstring>
#define VMAX 1001
#define INF 2147483647
#define coord pair<double, double>

using namespace std;

vector<int> adjacencyList[VMAX];
double distances[VMAX][VMAX];
int nStates, n, r;
double sumRoads, sumRailroads;

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
    double q[n];
    int s[n], pi[n];
    for (int i = 0; i < n; i++) {
        q[i] = (i==0?0:INF);
        s[i] = 0;
        pi[i] = -1;
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

        if (q[v] > r) {
            sumRailroads += q[v];
            nStates++;
        }
        else {
            sumRoads += q[v];
        }

        for (int w : adjacencyList[v]) {
            if (distances[v][w] < q[w]) {
                q[w] = distances[v][w];
                fila.push(make_pair(w, q[w]));
                pi[w] = v;
            }
        }
    }
}

int main()
{
    int nInputs, nCase = 1;
    cin >> nInputs;
    while (nInputs--) {
        cin >> n >> r;
        coord coords[VMAX];
        for (int i = 0; i < n; i++) {
            cin >> coords[i].first >> coords[i].second;
        }

        memset(distances, 0, VMAX*VMAX);
        sumRoads = 0; sumRailroads = 0; nStates = 1;
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

        cout << "Case #" << nCase++ << ": " << nStates << ' ' << round(sumRoads) << ' ' << round(sumRailroads) << endl;
    }
    return 0;
}
