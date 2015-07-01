#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    double r,side;                         //bug is there will be double data in input 
    while(cin>>r>>side)
    {
        
        double area;
        double s=sin(2*acos(-1) / side);
        
        area=r*r*s*side/2;
        printf("%.3lf\n",area); 
    }
    return 0;
}
