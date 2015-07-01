#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int x0=0,y0=0,x1,y1,r1,r2;
    while(cin>>x1>>y1>>r1>>r2)
    {
        if(!x1&&!y1&&!r1&&!r2)
            break;
        int c1x,c1y,c2x,c2y;
        c1x=x0+r1;
        c1y=y0+r1;
        c2x=x1-r2;
        c2y=y1-r2;
        double check=sqrt((c2x-c1x)*(c2x-c1x)+(c2y-c1y)*(c2y-c1y));
        if(check>=(r1+r2)&&2*r1<=x1&&2*r2<=x1&&2*r1<=y1&&2*r2<=y1)
            cout<<"S\n";
        else 
            cout<<"N\n";
    }
    return 0;
}
