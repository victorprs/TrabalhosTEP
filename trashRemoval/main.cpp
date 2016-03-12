#include <iostream>
#include <complex>
#include <stdio.h>
using namespace std;
typedef complex<double> point;

#define PI 3.141592653589793
#define EPS 0.000000001
#define X real()
#define Y imag()
#define cross(a,b) ((conj(a)*b).imag())
#define dot(a,b) ((conj(a)*b).real())
#define vec(a,b) ((b)-(a))

double MIN(double x,double y)
{
    return (x>y) ? y : x;
}
double MAX(double x,double y)
{
    return (x>y) ? x : y;
}
void rotateAbout(point &v,double t,point &a)
{
      v=(vec(a,v));
      v=(v)*exp(point(0,t));
      v+=a;
}
int main()
{
    int n;
    int t= 1;
     while(scanf("%d",&n)&&n!=0)
    {
        point arr[n];
        double x,y;
        for (int i=0;i<n;i++){
            scanf("%lf %lf",&x,&y);
            arr[i] = point(x,y);
        }
        point lines[n*n][2];
        int index=0;
        for (int i=0;i<n;i++)
        for (int j=i;j<n;j++)if(i!=j){
            lines[index][0] = arr[i];
            lines[index++][1] = arr[j];
        }

        double min = 10000000;
        for (int i=0;i<index;i++)
        {
            point p1,p2;
            if(lines[i][0].Y<lines[i][1].Y)
            {
                p1 = lines[i][0];
                p2 = lines[i][1];

            }
            else {
             p2 = lines[i][0];
             p1 = lines[i][1];

            }
            p2 = (p2-p1);
            // get the angle of rotation
            double angle = atan2(p2.Y,p2.X);
            angle=(angle*180)/PI;
            angle = 90-angle;
            angle = (angle*PI)/180;
            double minX =0;
            double maxX=0;
            for(int j=0;j<n;j++)
            {
                point p = arr[j];
                rotateAbout(p,angle,p1);
                maxX = MAX(maxX,p.X-p1.X);
                minX = MIN(minX,p.X-p1.X);

            }
            min = MIN(min,maxX-minX);
        }
        min*=100;
        min = ceil(min);
        min/=100;
        printf("Case %d: %.2f\n",t++,min);
    }
    return 0;
}
