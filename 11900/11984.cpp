#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    while(cin>>t)
    {
        for(int i=1;i<=t;i++)
        {
            double c,d;
            cin>>c>>d;
            d=d*5/9;
            c+=d;
            cout<<"Case "<<i<<": ";
            printf("%.2lf\n",c);
        }
    }
}
