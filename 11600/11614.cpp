#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    long long int n, t, r;
    cin>>n;
    while(n--)
    {
        cin>>t;
        r = (long long int)((-1+sqrt(1+8*t))/2);
        cout<<r<<"\n";
    }
    return 0;
}
