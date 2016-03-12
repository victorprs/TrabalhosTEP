#include <iostream>
#include <map>

using namespace std;

int maxFriends = 0;

class Node {
public:
    int parent;
    int rank;
    int setSize;
    Node() : parent(0), rank(0), setSize(0){}
    Node(int i) :
        parent(i),
        rank(0),
        setSize(1){}


    inline bool operator==(Node r) {
        return (this->parent == r.parent && this->setSize == r.setSize && this->rank == r.rank);
    }
};

map<int, Node> forest;

int uFind(int x) {
    if (forest[x].parent != x) {
        forest[x].parent = uFind(forest[x].parent);
    }
    return forest[x].parent;
}


void uUnion(int x, int y) {
    Node* xRoot = &forest[uFind(x)];
    Node* yRoot = &forest[uFind(y)];

    if (xRoot == yRoot)
        return;

    if (xRoot->rank < yRoot->rank) {
        xRoot->parent = yRoot->parent;

        yRoot->setSize += xRoot->setSize;
        if (yRoot->setSize > maxFriends)
            maxFriends = yRoot->setSize;
    }
    else if (xRoot->rank > yRoot->rank) {
        yRoot->parent = xRoot->parent;

        xRoot->setSize += yRoot->setSize;
        if (xRoot->setSize > maxFriends)
            maxFriends = xRoot->setSize;
    }
    else {
        yRoot->parent = xRoot->parent;
        xRoot->rank++;

        xRoot->setSize += yRoot->setSize;
        if (xRoot->setSize > maxFriends)
            maxFriends = xRoot->setSize;
    }
}


int main()
{
    int nInputs;
    cin >> nInputs;
    while (nInputs--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;

            map<int, Node>::iterator it = forest.find(a);
            if (it == forest.end()) {
                forest[a] = Node(a);
            }

            it = forest.find(b);
            if (it == forest.end()) {
                forest[b] = Node(b);
            }
            uUnion(a, b);
        }

        cout << maxFriends << endl;
        forest.clear();
        maxFriends = 0;

    }
    return 0;
}
