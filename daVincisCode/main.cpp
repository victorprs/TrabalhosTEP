#include <iostream>

using namespace std;

static int FIBONACCI[] =
{1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,
28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,
5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,
267914296,433494437,701408733,1134903170,1836311903};


string cleanString(string cipher)
{
    string result = cipher.substr();
    for (int i = 0; i < result.length(); i++)
    {
        if (result[i] < 65 || result[i] > 90)
            result.erase(i--, 1);
    }

    return result;
}

int findIndexInFib(int number)
{
    for (int i = 0; i < 41; i++)
    {
        if (number == FIBONACCI[i])
            return i;
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int numbers[n];
        for (int i = 0; i < n; i++)
        {
            cin >> numbers[i];
        }

        cin.ignore();

        string cipher;
        getline(cin, cipher);

        string clearedCipher = cleanString(cipher);

        char answer[101];

        for (int i = 0; i < 100; i++) answer[i] = ' ';
        answer[100] = '\0';

        int lastIndex = 0;
        for (int i = 0; i < n; i++)
        {
            int index = findIndexInFib(numbers[i]);
            answer[index] = clearedCipher[i];
            if (index > lastIndex)
                lastIndex = index;
        }

        string newAnswer = answer;
        string formattedAnswer = newAnswer.substr(0, lastIndex+1);

        cout << formattedAnswer  << endl;

    }


    return 0;
}
