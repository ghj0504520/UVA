#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std; 
struct point
{
    double x,y;
};
int main()
{
    point three[3];
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>three[0].x>>three[0].y>>three[1].x>>three[1].y>>three[2].x>>three[2].y;
        double area=(three[0].x-three[1].x)*(three[2].y-three[1].y)-(three[0].y-three[1].y)*(three[2].x-three[1].x);
        area/=2;
        area/=7;
        printf("%.0lf\n",fabs(area));
    }
    return 0;
}
