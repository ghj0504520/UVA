#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int val[21+1]={0};
    long long dp[10000+10]={0};
    
    for(int i=1 ; i<=21 ; i++)
        val[i]=i*i*i;
    dp[0]=1;
    for(int i=1 ; i <= 21 ; i++)
    {
        for(int j = val[i] ; j <= 10000 ; j++ )
        {
            dp[j] += dp[j - val[i]];
        }
    }
    
    int q;
    while(cin>>q)
        cout<<dp[q]<<"\n";
    
    return 0;
}
