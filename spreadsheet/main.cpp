#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>

#define par pair<int, int>

using namespace std;

int toint(string s) {
    return atoi(s.c_str());
}

vector<par> rawToIndex(string aux) {
    vector<par> indexes;
    aux = aux.substr(1, aux.length()-1);

    stringstream sstream(aux);
    string item;
    while (getline(sstream, item, '+')) {
        int i = 0;
        int j = 0;
        bool change = false;
        for (int c = 0; c < item.length(); c++) {
            if (item[c] > 47 && item[c] < 58)
                i = i * 10 + (item[c] - '0');
            else {
                j = j * 26 + (item[c] - 'A' + 1);
            }
        }

        indexes.push_back(par(i - 1, j - 1));
    }
    return indexes;
}

int compute(int i, vector<par> indexes, vector<vector<int*>> res) {
    int total = 0;
    for (par p : indexes) {
        total += *res[p.first][p.second];
    }
    return total;
}

int main()
{
    int nInputs, n, m;
    cin >> nInputs;
    while (nInputs--) {
        cin >> m >> n;

        vector<vector<int*>> res(n);

        vector<vector<par>> tab;

        vector<par> tabs;
        string aux;
        int nulls = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> aux;
                if (aux[0] == '=') {
                    tab.push_back(rawToIndex(aux));
                    tabs.push_back(par(i,j));
                    res[i].push_back(NULL);
                    nulls++;
                }
                else {
                    res[i].push_back(new int(toint(aux)));
                }
            }
        }


        while (nulls) {
            for (int i = tab.size()-1; i >= 0; i--) {
                int j = 0;
                for (par index : tab[i]) {
                    if (!res[index.first][index.second]) {
                        continue;
                    }
                    ++j;
                }
                if (j == tab[i].size() && j != 0) {
                    nulls--;
                    res[tabs[i].first][tabs[i].second] = new int(compute(i, tab[i], res));
                    tab.erase(tab.begin()+i);
                    tabs.erase(tabs.begin()+i);
                }
            }
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << *res[i][j];
                if (j == m - 1)
                    cout << endl;
                else
                    cout << " ";
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                delete res[i][j];
        }

    }
    return 0;
}
