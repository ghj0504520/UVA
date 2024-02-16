#include <cmath>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,p,q,s=0;
        cin>>n;
        int o[1000+10][2]={0};
        
        int M=35;
        int dp[1000+10][M]={0};
        
        for(int i=0 ; i<n; i++)
            cin>>o[i][0]>>o[i][1];
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<=M ; j++)
            {
                if(j>=o[i][1])
                    dp[i+1][j]=max(dp[i][j],dp[i][j-o[i][1]]+o[i][0]);
                else dp[i+1][j]=dp[i][j];
            }
        }
        
        
        
        cin>>p;
        for (int i = 0; i < p; i++)
        {
            cin>>q;
            s += dp[n][q];
        }
        cout<<s<<"\n";
    }
    return 0;
}
