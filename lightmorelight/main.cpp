#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    while (true)
    {
        unsigned int n, root;
        scanf("%u", &n);
        if (!n) break;

        root = sqrt(n);
        if (root * root == n)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
