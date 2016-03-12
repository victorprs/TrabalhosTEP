#include <cstdio>
#include <vector>
#include <limits>
#include <cmath>
#define point pair<double,double>

using namespace std;

point m;
vector<point> lineSegments;

double lengthSqr(point o, point p) {
    double x = p.first - o.first;
    double y = p.second - o.second;
    return x*x + y*y;
}

double dot(point o, point p) {
    return o.first * p.first + o.second * p.second;
}

point vecSub(point b, point a) {
    return point(b.first - a.first, b.second - a.second);
}

point vecAdd(point a, point b) {
    return point(a.first + b.first, a.second + b.second);
}

point scalarMul(point a, double k) {
    return point(a.first * k, a.second * k);
}

point closestPointOnLineSegment(point p, point a, point b) {
    point ap = vecSub(p, a);
    point ab = vecSub(b, a);

    double magAB = lengthSqr(point(0,0), ab);
    double abapDot = dot(ap, ab);
    double distance = abapDot / magAB;

    if (distance < 0)
        return a;
    else if (distance > 1)
        return b;
    else
        return vecAdd(a, scalarMul(ab, distance));
}

int main()
{
    int n;
    double x, y;

    while (scanf("%lf\n%lf", &x, &y) != EOF) {
        m = point(x, y);
        scanf("%d", &n);

        for (int i = 0; i < n + 1; i++) {
            scanf("%lf\n%lf", &x, &y);
            lineSegments.push_back(point(x,y));
        }

        double answer = std::numeric_limits<double>::max();
        point answerP, tP;
        for (int i = 0; i < n; i++) {
            tP = closestPointOnLineSegment(m, lineSegments[i], lineSegments[i+1]);
            double t = lengthSqr(m, tP);
            if (t < answer) {
                answer = t;
                answerP = tP;
            }
        }

        printf("%.4f\n%.4f\n", answerP.first, answerP.second);

        lineSegments.clear();
    }
    return 0;
}
