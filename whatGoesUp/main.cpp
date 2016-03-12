#include <iostream>
#include <vector>

using namespace std;

vector<int> seq, p, lis;

int main()
{
    int n;
    while (cin >> n) {
        seq.push_back(n);
    }

    vector<int> p(seq.size());
    int u, v;

    lis.push_back(0);
    for (int i = 1; i < seq.size(); i++) {
        if (seq[lis.back()] < seq[i]) {
            p[i] = lis.back();
            lis.push_back(i);
            continue;
        }

        for (u = 0, v = lis.size() - 1; u < v;) {
            int c = (u + v) / 2;
            if (seq[lis[c]] < seq[i])
                u = c + 1;
            else
                v = c;
        }

        if (seq[i] < seq[lis[u]]) {
            if (u > 0)
                p[i] = lis[u - 1];
            lis[u] = i;
        }
    }

    for (u = lis.size(), v = lis.back(); u--; v = p[v])
        lis[u] = v;

    cout << lis.size() << endl << '-' << endl;
    for (int i = 0; i < lis.size(); i++)
        cout << seq[lis[i]] << endl;
    return 0;
}
