#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        if(a==b&&b==c)
            cout<<"*\n";
        else if(a==b&&b!=c)
            cout<<"C\n";
        else if(a!=b&&b==c)
            cout<<"A\n";
        else if(a==c&&b!=c)
            cout<<"B\n";
    }
    return 0;
}
