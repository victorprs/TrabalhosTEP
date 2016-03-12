#include <iostream>
#include <vector>

using namespace std;

void siftDown( int *a, int start, int end)
{
    int root = start;

    while ( root*2+1 < end ) {
        int child = 2*root + 1;
        if ((child + 1 < end) && (a[child] < a[child+1])) {
            child += 1;
        }
        if ((a[root] < a[child])) {
            swap( a[child], a[root] );
            root = child;
        }
        else
            return;
    }
}

void heapsort( int *a, int count)
{
    int start, end;

    for (start = (count-2)/2; start >=0; start--) {
        siftDown( a, start, count);
    }

    for (end=count-1; end > 0; end--) {
        swap(a[end],a[0]);
        siftDown(a, 0, end);
    }
}

int main()
{
    int k, M, N;
    cin >> k;

    int oldUInt = 0;
    for (int kCount = 0; kCount < k; kCount++)
    {
        cin >> M;
        cin >> N;

        int A[M];
        int u[N];

        int insArray[M];

        for (int i = 0; i < M; i++)
        {
            cin >> A[i];
        }

        for (int i = 0; i < N; i++)
        {
            int uInt;
            cin >> uInt;

            for (int j = oldUInt; j < uInt; j++)
            {
                insArray[j] = A[j];
            }

            oldUInt = uInt;

            heapsort(insArray, uInt);

            cout << insArray[i] << endl;
        }
    }

    return 0;
}
