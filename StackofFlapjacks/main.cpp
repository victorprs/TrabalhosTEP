#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>

using namespace std;

class Vector2
{
public:
    int indexDest;
    int indexSource;

};

void flip(vector<int>& curStack, int limit)
{
    for (int i = 0; i < limit / 2.f ; i++)
    {
        swap(curStack[i], curStack[limit - i]);
    }
}

bool isSorted(vector<int> curStack, int limit)
{
    bool sorted = true;
    for (int i = 0; i <= limit - 1; i++)
    {
        for (int j = i+1; j <= limit; j++)
        {
            if (curStack[i] > curStack[j])
            {
                sorted = false;
            }
        }
    }
    return sorted;
}

Vector2 posToFlip(vector<int> curStack)
{
    Vector2 pos;
    pos.indexDest = -1;
    pos.indexSource = -1;
    for (int i = curStack.size() - 1; i > -1; i--)
    {
        for (int j = i-1; j > -1; j--)
        {
            if (curStack[i] < curStack[j])
            {
                if (pos.indexSource == -1)
                {
                    pos.indexDest = i;
                    pos.indexSource = j;
                }
                else if (curStack[j] > curStack[pos.indexSource])
                {
                    pos.indexDest = i;
                    pos.indexSource = j;
                }
            }
        }
    }
    return pos;
}

void sortStack(vector<int>& curStack)
{
    string result;

    std::stringstream out;

    bool sorted;
    for (int i = curStack.size() - 1; i > -1; i--)
    {
        sorted = isSorted(curStack, i);
        if (sorted)
        {
            out << " 0";
            break;
        }
        else
        {
            Vector2 pos = posToFlip(curStack);
            if (pos.indexSource != 0)
            {
                flip(curStack, pos.indexSource);
                out << " " << curStack.size() - pos.indexSource;
            }
            flip(curStack, pos.indexDest);
            out << " " << curStack.size() - pos.indexDest;
        }
    }

    result = out.str();
    result = result.substr(1, result.length());
    cout << result << endl;
}

int main()
{
    string line;
    while(getline(cin, line))
    {
        vector<int> curStack;

        int stackCounter = 0;
        int cursor = 0;
        while (cursor < line.length())
        {
            int found = line.find(' ', cursor);
            int newNumber;
            if (found == -1)
            {
                found = line.length();
                newNumber = atoi(line.substr(cursor, line.length()).c_str());
            }
            else
                newNumber = atoi(line.substr(cursor, found - cursor).c_str());

            curStack.insert(curStack.end(), newNumber);
            cursor = found+1;
        }

        for (int i = 0; i < curStack.size() - 1; i++)
        {
            cout << curStack[i] << " ";
        }
        cout << curStack[curStack.size() - 1] << endl;
        sortStack(curStack);
    }

    return 0;
}
