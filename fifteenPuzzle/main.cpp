#include <iostream>
#include <queue>
#include <array>
#include <cmath>
#define board array<array<int, 4>,4>

using namespace std;

string resultPath = "";

pair<int, int> goalIndex (int c) {
    switch(c) {
        case 1:
            return make_pair(0,0);
            break;
        case 2:
            return make_pair(0,1);
            break;
        case 3:
            return make_pair(0,2);
            break;
        case 4:
            return make_pair(0,3);
            break;
        case 5:
            return make_pair(1,0);
            break;
        case 6:
            return make_pair(1,1);
            break;
        case 7:
            return make_pair(1,2);
            break;
        case 8:
            return make_pair(1,3);
            break;
        case 9:
            return make_pair(2,0);
            break;
        case 10:
            return make_pair(2,1);
            break;
        case 11:
            return make_pair(2,2);
            break;
        case 12:
            return make_pair(2,3);
            break;
        case 13:
            return make_pair(3,0);
            break;
        case 14:
            return make_pair(3,1);
            break;
        case 15:
            return make_pair(3,2);
            break;
        case 0:
            return make_pair(3,3);
            break;
    }
}

class State {
public:
    board brd;
    int f, g, h;
    string path;
    State() {}
    State(board b, int gN, string str) : brd(b), g(gN){
        h = 0;
        null = false;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (brd[i][j] != 0) {
                    pair<int, int> coord = goalIndex(brd[i][j]);
                    h += abs(i - coord.first) + abs(j - coord.second);
                }
            }
        }

        f = g + h;
        path += str;
    }

    bool notNull() {
        return !null;
    }

    bool isGoal() const {
        if (null)
            return false;
        if (brd[0][0] == 1 &&
            brd[0][1] == 2 &&
            brd[0][2] == 3 &&
            brd[0][3] == 4 &&
            brd[1][0] == 5 &&
            brd[1][1] == 6 &&
            brd[1][2] == 7 &&
            brd[1][3] == 8 &&
            brd[2][0] == 9 &&
            brd[2][1] == 10 &&
            brd[2][2] == 11 &&
            brd[2][3] == 12 &&
            brd[3][0] == 13 &&
            brd[3][1] == 14 &&
            brd[3][2] == 15 &&
            brd[3][3] == 0)
                return true;
        return false;
    }

    array<State,4> generateNextStates() {
        array<State,4> nS;

        int i, j, sc = 0;

        board curBoard = brd;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (curBoard[i][j] == 0) {
                    if (j != 3 && path[path.length()-1] != 'L') {
                        swap(curBoard[i][j], curBoard[i][j+1]);
                        nS[sc++]= State(curBoard, g+1, path + "R");
                        swap(curBoard[i][j], curBoard[i][j+1]);
                    }
                    if (i != 0 && path[path.length()-1] != 'D') {
                        swap(curBoard[i-1][j], curBoard[i][j]);
                        nS[sc++]= State(curBoard, g+1, path + "U");
                        swap(curBoard[i-1][j], curBoard[i][j]);
                    }
                    if (j != 0 && path[path.length()-1] != 'R') {
                        swap(curBoard[i][j], curBoard[i][j-1]);
                        nS[sc++]= State(curBoard, g+1, path + "L");
                        swap(curBoard[i][j], curBoard[i][j-1]);
                    }
                    if (i != 3 && path[path.length()-1] != 'U') {
                        swap(curBoard[i+1][j], curBoard[i][j]);
                        nS[sc++]= State(curBoard, g+1, path + "D");
                        swap(curBoard[i+1][j], curBoard[i][j]);
                    }
                    return nS;
                }

            }
        }
    }

private:
    bool null = true;
};

board initial;

State asearch(State st, int bound) {
    if (st.isGoal())
        return st;
    else {
        if (st.notNull()) {
            for (State s : st.generateNextStates()) {
                if (s.f <= bound) {
                    State st2 = asearch(s, bound);
                    if (st2.isGoal())
                        return st2;
                }
            }
        }
        return State();
    }
}

int IDAStar(State root) {
    int bound = root.h;
    while (true) {
        State st = asearch(root, bound);
        if (st.isGoal()) {
            resultPath = st.path;
            return st.path.length();
        }
        bound += 5;
    }
}

bool isSolvable(State st) {
    int f[16];

    pair<int, int> zero;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            f[i*4+j] = st.brd[i][j];
            if (st.brd[i][j] == 0) {
                zero.first = i;
                zero.second = j;
            }
        }
    }

    int nOfInversions = 0;
    for (int i = 0; i < 16; i++) {
        for (int j = i+1; j < 16; j++) {
            if (f[i] == 0 || f[j] == 0)
                continue;

            if (f[i] > f[j])
                nOfInversions++;
        }
    }

    if ((4 - zero.first) % 2 == 0) {
        return nOfInversions % 2 == 1;
    }
    else {
        return nOfInversions % 2 == 0;
    }
}

int main()
{
    int nInputs;
    cin >> nInputs;
    while (nInputs--) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> initial[i][j];
            }
        }
        State st1(initial, 0, "");

        if (isSolvable(st1)) {
            IDAStar(st1);
            cout << resultPath << endl;
        }
        else
            cout << "This puzzle is not solvable." << endl;

        resultPath = "";
    }

    return 0;
}
