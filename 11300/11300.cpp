#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long coin[1000010],algebra[1000010];
long long algebra_medium,average=0,sum=0;
long long int avg(long long int k[],int p)
{
    long long f_sum=0;
    for(int i=0;i<p;i++)
        f_sum+=k[i];
    f_sum/=p;
    return f_sum;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(coin,0,sizeof(coin));
        average=0;
        sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&coin[i]);
        }
        average=avg(coin,n);
        
        memset(algebra,0,sizeof(algebra));
        for(int i=1;i<n;i++)//algorithm
        {
            algebra[i]=algebra[i-1]+coin[i]-average;
        }
        sort(algebra,algebra+n);
        
        n%2==1? algebra_medium=algebra[n/2]:algebra_medium=algebra[(n+1)/2];
        for(int i=0;i<n;i++)
        {
            sum+=abs(algebra_medium-algebra[i]);
        }
        printf("%lld\n",sum);
        //cout<<sum<<'\n';    
    }
    return 0;
}
