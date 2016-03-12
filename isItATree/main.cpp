#include <iostream>
#include <map>
#include <list>
#include <cstring>

using namespace std;

map<int, list<int>> adjacencyList, incidenceList;
map<int, int> c, roots;
int nOfVertices = 0, visitedVertices = 0, nOfEdges = 0;

bool dfs(int r, int v) {
    c[v] = 1;
    for (auto& w: adjacencyList[v]) {
        if (c[w] == 0) {
            nOfEdges++;
            if (!dfs(r, w))
                return false;
        }
        else {
            if (roots[w] && r != w)
                return true;
            else
                return false;
        }
    }
    c[v] = 2;
    return true;
}

bool isATree(int nOfVertices) {
    for (auto& x: incidenceList) {
        nOfVertices++;
        if (x.second.empty()) {
            roots[x.first] = 1;
            if (!dfs(x.first, x.first))
                return false;
        }
    }

    if (nOfVertices > 0 && nOfEdges != nOfVertices - 1)
        return false;

    for (auto& color: c) {
        if (color.second == 0)
            return false;
    }
    return true;
}

int main()
{
    int a, b;
    int nCase = 1;
    int graphSize = 0;
    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0) {
            if (isATree(nOfVertices))
                cout << "Case " << nCase++ << " is a tree." << endl;
            else
                cout << "Case " << nCase++ << " is not a tree." << endl;
            adjacencyList.clear();
            incidenceList.clear();
            c.clear();
            nOfVertices = 0;
            nOfEdges = 0;
            visitedVertices = 0;
        }
        else if (a < 0 && b < 0)
            break;
        else {
            graphSize++;
            c[a]; c[b]; roots[a]; roots[b];
            adjacencyList[a].push_back(b);
            adjacencyList[b];
            incidenceList[b].push_back(a);
            incidenceList[a];
        }
    }
    return 0;
}
