#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

bool numbers[10000000];
long long primes[1000000];

int main()
{
    memset(numbers,true,sizeof(numbers));
    numbers[0] = 0; numbers[1] = 0;
    long long nPrimes = 0;
    for (long long i = 2; i < 10000000; i++)
    {
        if (numbers[i])
        {
            primes[nPrimes++] = i;
            for (long long j = i*i, k = 1; j < 10000000; j = i*i + k++ *i)
            {
                numbers[j] = 0;
            }
        }
    }

    int counter = 0;
    long long lpd = 0;
    while (true)
    {
        long long n, i, j;
        scanf("%lld", &n);
        if (!n) break;
        if (n < 0) n *= -1;

        for(i=0,counter=0;i<nPrimes&&n>1&&primes[i]<=n;i++)
        {
            if(n%primes[i]==0)
            {
                counter++;
                while(n>1 && n%primes[i]==0)
                {
                    n/=primes[i];
                }
                lpd=primes[i];
            }
            if(n==1) break;
        }
        if(n==1)
        {
            if(counter>1) printf("%lld\n",lpd);
            else printf("-1\n");
        }
        else
        {
            if(counter>0) printf("%lld\n",n);
            else printf("-1\n");
        }

    }

    return 0;
}
