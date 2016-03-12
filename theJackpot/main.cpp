#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n != 0) {
        int tab[n];
        int maxSoma = 0;
        for (int i = 0; i < n; i++)
            tab[i] = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (i == 0) {
                if (a > 0) {
                    tab[i] = a;
                    maxSoma = a;
                }
                continue;
            }

            tab[i] = max(0, tab[i-1] + a);

            maxSoma = max(maxSoma, tab[i]);

        }

        if (maxSoma > 0)
            cout << "The maximum winning streak is " << maxSoma << "." << endl;
        else
            cout << "Losing streak." << endl;

        cin >> n;
    }
    return 0;
}
