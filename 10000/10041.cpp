#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            long long int n;
            cin>>n;
            long long int location[n+1];
            for(int i=1;i<=n;i++)
            {    
                cin>>location[i];
            }
            sort(location+1,location+n+1);
            long long int m;
            n%2==0? m=n/2 : m=(n+1)/2;
            long long int sum=0 ,s;
            for(int i=1;i<=n;i++)
            {
                s=abs(location[i]-location[m]);
                sum+=s;
            }
            cout<<sum<<endl;
        }
    }
}
