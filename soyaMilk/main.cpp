#include <cstdio>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

int l, w, h, theta;

int main()
{
    while (scanf("%d %d %d %d", &l, &w, &h, &theta) != EOF) {
        double base = l / (cos(theta * M_PI / 180));
        double h1 = base * (sin(theta * M_PI / 180));
        double diagonal = sqrt(l*l + h*h);

        double area;
        if (base <= diagonal)
            area = l * h - h1 * l / 2;
        else
            area = (h / tan(theta * M_PI / 180)) * h / 2;

        printf("%.3f mL\n", area * w);
    }
    return 0;
}
