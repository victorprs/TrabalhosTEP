#include <iostream>

using namespace std;

int f(int n)
{
    if (n == 1)
        return 1;
    return 1 + f(n - f(f(n-1)));
}

int main()
{
    while (true)
    {
        int n;
        cin >> n;

        if (n == 0) break;

        int sqrtN = sqrt(n);

        cout << f(n) << endl;
    }
    return 0;
}
