#include<iostream>
using namespace std;
int main()
{
    int t;
    while(cin>>t)
    {
        for(int i=1;i<=t;i++)
        {
            int n;
            cin>>n;
            int p[n];
            for(int j=0;j<n;j++)
                cin>>p[j];
            cout<<"Case "<<i<<": "<<p[(n+1)/2-1]<<'\n';
        }
    }
}
