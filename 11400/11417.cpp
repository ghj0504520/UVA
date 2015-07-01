#include<iostream>
using namespace std;

long long int gcd(long long int a,long long int b);

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
            break;
        long long int sum=0;
        for(long long int i=1;i<n;i++)
        {
            for(long long int j=i+1;j<=n;j++)
            {
                sum+=gcd(i,j);
            }
        }
        cout<<sum<<endl;
    }
    
}

long long int gcd(long long int a,long long int b)
{
    if(a<=b)
    {
        long long int swap=a;
        a=b;
        b=swap;
    }
    long long int mod=a%b;
    while(mod!=0)
    {
        a=b;
        b=mod;
        mod=a%b;
    }
  
    return b;
}
