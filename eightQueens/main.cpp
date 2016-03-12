#include <iostream>
#include <array>
#include <cmath>

#define N 8

using namespace std;

array<int,N> n, in;

bool valid(int index, int pos) {
    for (int i = 0; i < index; i++) {
        if (pos == n[i] || abs(index - i) == abs(pos - n[i]))
            return false;
    }
    return true;
}

int search(int index) {
    if (index == 8) return 0;

    int total = 100000;

    for (int pos = 0; pos < N; pos++) {
        if (valid(index, pos)) {
            n[index] = pos;
            if (pos == in[index])
                total = min(total, search(index + 1));
            else
                total = min(total, 1 + search(index + 1));
        }
    }

    return total;
}

int main()
{
    int nCase = 1;
    while (cin >> in[0]) {
        cin >> in[1] >> in[2] >> in[3] >> in[4] >> in[5] >> in[6] >> in[7];

        for (int i = 0; i < N; i++){
            n[i] = --in[i];
        }

        cout << "Case " << nCase++ << ": " << search(0) << endl;

    }
    return 0;
}
