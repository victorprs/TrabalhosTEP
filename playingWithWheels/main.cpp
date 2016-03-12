#include <iostream>
#include <cmath>
#include <unordered_map>
#include <queue>
#include <functional>
#define WS 4
#define MAX 10000

using namespace std;

int s[WS], t[WS], bad[MAX][WS], nOfBad;

class State {
public:
    int n[WS];
    int f, g;
    State() {}
    State(int m[WS], int fN, int gN) {
        n[0] = m[0]; n[1] = m[1]; n[2] = m[2]; n[3] = m[3];
        f = fN;
        g = gN;
    }


    bool equals(int st[WS]) const {
        for (int i = 0; i < WS; i++) {
            if (n[i] != st[i])
                return false;
        }
        return true;
    }

    bool isBad() const{
        for (int i = 0; i < nOfBad; i++) {
            if (equals(bad[i]))
                return true;
        }
        return false;
    }

    void assignF(int gN) {
        int hN = 0;
        for (int i = 0; i < WS; i++) {
            hN += (abs(t[i] - n[i]) > 5? 10 - abs(t[i] - n[i]) : abs(t[i] - n[i]));
        }
        f = gN + hN;
        g = gN;
    }

    bool operator<(const State &st) const {
        if (f == st.f)
            return g < st.g;
        return f > st.f;
    }

    int intForm() const{
        return n[0] * 1000 + n[1] * 100 + n[2] * 10 + n[3];
    }
};

priority_queue<State> pq;
unordered_map<int, bool> um;

int aStar() {
    int i = 0;
    while (!pq.empty()) {
        if (pq.top().equals(t))
            return pq.top().f;

        State curState = pq.top();
        pq.pop();

        for (int i = 0; i < WS; i++) {
            State newState;
            for (int j = 0; j < WS; j++) {
                newState.n[j] = (i==j? curState.n[j]+1: curState.n[j]);
                if (newState.n[j] == 10) newState.n[j] = 0;
                if (newState.n[j] == -1) newState.n[j] = 9;
            }

            newState.assignF(curState.g + 1);
            auto it = um.find(newState.intForm());
            if (!newState.isBad() && it == um.end()) {
                pq.push(newState);
                um[newState.intForm()] = true;
            }
            for (int j = 0; j < WS; j++) {
                newState.n[j] = (i==j? curState.n[j]-1: curState.n[j]);
                if (newState.n[j] == 10) newState.n[j] = 0;
                if (newState.n[j] == -1) newState.n[j] = 9;
            }
            newState.assignF(curState.g + 1);

            //cout << newState.intForm() << ' ';
            it = um.find(newState.intForm());
            if (!newState.isBad() && it == um.end()) {
                um[newState.intForm()] = true;
                pq.push(newState);
            }
        }
    }

    return -1;
}

int main()
{
    int nInputs;
    cin >> nInputs;
    while (nInputs--) {
        cin >> s[0] >> s[1] >> s[2] >>s[3];
        cin >> t[0] >> t[1] >> t[2] >>t[3];
        cin >> nOfBad;
        for (int i = 0; i < nOfBad; i++) {
            cin >> bad[i][0] >> bad[i][1] >> bad[i][2] >> bad[i][3];
        }

        State st1(s, 0, 0);
        st1.assignF(0);
        pq.push(st1);
        um[st1.intForm()] = true;
        cout << aStar() << endl;

        pq = priority_queue<State>();
        um.clear();

    }
    return 0;
}
