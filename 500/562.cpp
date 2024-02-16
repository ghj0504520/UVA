#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;

#define M 50000+10
int dp[100+10][M];

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        
        int o[100+10]={0};
        memset(dp,0,sizeof(dp));
        
        int sum=0;
        for(int i=0 ; i<n; i++)
        {    
            cin>>o[i];
            sum+=o[i];
        }
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<=sum/2 ; j++)
            {
                if(j>=o[i])
                    dp[i+1][j]=max(dp[i][j],dp[i][j-o[i]]+o[i]);
                else dp[i+1][j]=dp[i][j];
            }
        }cout<<sum-2*dp[n][sum/2]<<"\n";
    }
    return 0;
}
