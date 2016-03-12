#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

bool numbers[1000000];
unsigned int primes[70000];

int mainbak()
{
    memset(numbers,true,sizeof(numbers));
    numbers[0] = 0; numbers[1] = 0;
    unsigned int nPrimes = 0;
    for (unsigned int i = 2; i < 1000000; i++)
    {
        if (numbers[i])
        {
            primes[nPrimes++] = i;
            for (unsigned int j = i*i, k = 1; j < 1000000; j = i*i + k++ *i)
            {
                numbers[j] = 0;
            }
        }
    }

    while (true)
    {
        unsigned int n;
        scanf("%u", &n);
        if (!n) break;

        unsigned int nFactors = 1;
        for (unsigned int i = 0; i < sqrt(n); i++)
        {
            unsigned int exponent = 0;
            while (n%primes[i] == 0)
            {
                exponent++;
                n = n / primes[i];
                if (n == 1) break;
            }
            if (exponent != 0)
                nFactors *= (exponent+1);
            if (n == 1) break;
        }

        if (n != 1)
            nFactors *= 2;

        if (nFactors % 2 == 0)
            printf("no\n");
        else
            printf("yes\n");

    }
    return 0;
}
