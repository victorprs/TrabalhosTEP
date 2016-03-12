#include <iostream>
#include <string>

using namespace std;

char board[3][3];

bool oWon() {
    if ((board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') ||
        (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') ||
        (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') ||

        (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') ||
        (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') ||
        (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') ||

        (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') ||
        (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
        return true;

    return false;
}

bool xWon() {
    if ((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') ||
        (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') ||
        (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') ||

        (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') ||
        (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') ||
        (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') ||

        (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
        (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'))
        return true;

    return false;
}

int main()
{
    int nInputs;
    cin >> nInputs;
    while (nInputs--) {
        cin >> board[0];
        cin >> board[1];
        cin >> board[2];

        int nX = 0, nO = 0;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'X')
                    nX++;
                else if (board[i][j] == 'O')
                    nO++;
            }
        }

        if (nO > nX ||
            nX - nO > 1 ||
            (oWon() && xWon()) ||
            (oWon() && nX > nO) ||
            (xWon() && nX == nO))
            cout << "no" << endl;
        else
            cout << "yes" << endl;

    }
    return 0;
}
