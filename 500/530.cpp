#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        if(!n && !k)
            break;
        long long ans =1;
        if(n-k<k)
            k=n-k;
        for(int i=0;i<k;i++)
        {
            ans=ans*(n-i)/(1+i);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
