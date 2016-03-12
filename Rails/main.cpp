#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    while (N != 0)
    {
        int perm[N];
        for (int i = 0; i < N; i++)
        {
            cin >> perm[i];
            if (i == 0 && perm[i] == 0)
            {
                cout << endl;
                break;
            }

            if (i == N-1)
            {
                //body

            }
        }

        cin >> N;
    }

    return 0;
}
