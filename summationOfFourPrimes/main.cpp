#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

bool numbers[10000001];
unsigned int primes[1000000];

void goldbach(int n, int &a, int &b)
{
    for (int i = 0; i < sqrt(n); i++)
    {
        int y = n - primes[i];
        if (numbers[y])
        {
            a = primes[i];
            b = y;
            break;
        }
    }
}

int main()
{
    memset(numbers,true,sizeof(numbers));
    numbers[0] = 0; numbers[1] = 0;
    unsigned int nPrimes = 0;
    for (unsigned int i = 2; i < 10000001; i++)
    {
        if (numbers[i])
        {
            primes[nPrimes++] = i;
            for (unsigned int j = i*i, k = 1; j < 10000001; j = i*i + k++ *i)
            {
                numbers[j] = 0;
            }
        }
    }

    int n, a, b;
    while (scanf("%d", &n) != EOF)
    {
        if (n < 8)
        {
            printf("Impossible.\n");
            continue;
        }
        if (n % 2 == 0)
        {
            goldbach(n - 4, a, b);
            printf("2 2 %d %d\n", a, b);
        }
        else
        {
            goldbach(n - 5, a, b);
            printf("2 3 %d %d\n", a, b);
        }
    }
    return 0;
}
