#include <cstdio>
#define _USE_MATH_DEFINES
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Point {
public:
    Point(){}
    Point(int vx, int vy, int vz): x(vx), y(vy), z(vz) {
        d = x*x + y*y;
        angle = atan2(double(y),double(x));
    }
    int x, y, z;
    double d;
    double angle;

    const bool operator < (const Point point) const {
        return d < point.d;
    }
};

int main()
{
    int n, x, y, z, nCase = 1;
    while (scanf("%d", &n) && n != 0) {
        unordered_map<double, vector<Point>> pointsAtAngle;

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &x, &y, &z);
            Point p = Point(x, y, z);
            pointsAtAngle[p.angle].push_back(p);
        }

        vector<pair<int, int>> notVisible;
        for (auto &it : pointsAtAngle) {
            sort(it.second.begin(), it.second.end());

            int maxHeight = 0;
            for (auto &point : it.second) {
                if (point.z > maxHeight)
                    maxHeight = point.z;
                else
                    notVisible.push_back(pair<int, int>(point.x, point.y));
            }
        }
        sort(notVisible.begin(), notVisible.end());

        printf("Data set %d:\n", nCase++);
        if (notVisible.empty())
            printf("All the lights are visible.\n");
        else
            printf("Some lights are not visible:\n");

        for (auto &point : notVisible) {
            printf("x = %d, y = %d", point.first, point.second);
            if (point == *(notVisible.end()-1))
                printf(".\n");
            else
                printf(";\n");
        }
    }
    return 0;
}
