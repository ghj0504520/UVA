#include<iostream>
using namespace std;

struct data
{
    int a,b,c;
};

int main()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            int n;
            cin>>n; 
            data s[n];
            for(int i=0;i<n;i++)
                cin>>s[i].a>>s[i].b>>s[i].c;
            int sum=0;
            for(int i=0;i<n;i++)
            {
                sum+=s[i].a*s[i].c;
            }
            cout<<sum<<'\n';
        }
    }
}
