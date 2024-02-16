#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int q;
        cin>>q;
        int val[100+10];
        int n, sum=0;
        cin>>n;
        for(int i=0; i<n ; i++)
        {    
            cin>>val[i];
            if(sum<q)sum+=val[i];
        }
        
        int dp[10000*3+10];
        dp[0]=0;
        for (int i = 1; i <= sum; ++i)
            dp[i]=1e9;
        
        for (int i = 0; i < n; ++i) 
            for (int j = sum; j >= val[i]; --j) 
			    dp[j] = min(dp[j], dp[j - val[i]] + 1);

        while (dp[q] == 1e9) ++q;
		cout << q << " " << dp[q] << "\n";
    }
    return 0;
}
