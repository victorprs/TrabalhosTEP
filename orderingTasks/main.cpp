#include <iostream>
#include <queue>
#include <list>

using namespace std;

void topologicalSort(list<int> tasks[], list<int> adjOut[], int arSize)
{
    list<int> tS;

    int degreeOfVIn[arSize + 1];

    for (int i = 1; i <= arSize; i++)
    {
        degreeOfVIn[i] = 0;
        for (list<int>::iterator it = tasks[i].begin(); it != tasks[i].end(); it++)
        {
            degreeOfVIn[i]++;
        }
    }

    queue<int> F;

    for (int i = 1; i <= arSize; i++)
    {
        if (degreeOfVIn[i] == 0)
        {
            F.push(i);
        }
    }

    while (!F.empty())
    {
        int v = F.front();
        F.pop();
        tS.push_front(v);

        for (list<int>::iterator w = adjOut[v].begin(); w != adjOut[v].end(); w++)
        {
            if (--degreeOfVIn[*w] == 0)
            {
                F.push(*w);
            }
        }
    }

    for (list<int>::iterator it = tS.begin(); it != tS.end(); it++)
    {
        cout << *it;
        if (*it != tS.back())
            cout << " ";
    }
    cout << endl;
}

int main()
{
    int m = 0, n = 0;

    cin >> n;
    cin >> m;

    while (!(m == n && n == 0))
    {
        list<int> tasks[n+1];
        list<int> adjOut[n+1];

        for (int k = 0; k < m; k++)
        {
            int i, j;
            cin >> i;
            cin >> j;

            tasks[i].push_back(j);
            adjOut[j].push_back(i);
        }

        topologicalSort(tasks, adjOut, n);



        cin >> n;
        cin >> m;
    }

    return 0;

}
