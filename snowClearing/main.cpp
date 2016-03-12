#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

char buff[1000];
int main()
{
    int nInputs;
    cin >> nInputs;
    int blank = 0;
    while (nInputs--) {
        if (blank != 0)
            printf("\n");
        blank++;

        int h1, h2;
        cin >> h1 >> h2;
        cin.getline(buff, 256);
        double sum = 0;

        while (cin.getline(buff, 256)) {
            if (strlen(buff) == 0)
                break;

            int a, b, c, d;
            sscanf(buff, "%d %d %d %d", &a, &b, &c, &d);
            sum += (sqrt((a-c)*(a-c)+(b-d)*(b-d)))/1000;
        }

        sum *= 2;
        double ans = sum / 20;
        int hr = (int)(ans);
        double left = (ans - hr)*60;
        int minutes = (int)(left);
        left -= minutes;
        if(left > 0.5){
            minutes++;
        }
        if(minutes == 60){
            hr++;
            minutes -= 60;
        }
        printf("%d:%02d\n", hr, minutes);
    }
    return 0;
}
