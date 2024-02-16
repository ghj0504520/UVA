#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    string in;
    int h,m,s;
    double prev,v;
    double d=0;
    int pret=0,curt;
    while(getline(cin,in))
    {
        int cnt=sscanf(in.c_str(),"%d:%d:%d %lf",
                    &h,&m,&s,&v);
        curt=h*3600+m*60+s;
        d+=prev*(curt-pret)/3600.0;
        pret=curt;
        if(cnt==3)
            printf("%.2d:%.2d:%.2d %.2lf km\n",
                h,m,s,d);
        else prev=v;
    }
    return 0;
}
