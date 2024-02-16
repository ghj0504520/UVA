#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        int M,S;
        cin>>M>>S;
        
        vector< std::pair<int,int> > val;
        int a,b;
        for(int i=0 ; i<M ; i++)
        {
            cin>>a>>b;
            val.push_back(std::pair(a,b));
        }
        
        int dp[300+10][300+10]={0};
        for(int i=0 ; i<=300 ; i++)
            for(int j=0 ; j<=300 ; j++)
                dp[i][j]=1e9;
        dp[0][0]=0;
        
        for (auto it=val.begin() ; it!=val.end() ; it++)
		{
		    a=it->first;
		    b=it->second;
			for(int i=a ; i<=300 ; i++)
			    for(int j=b ; j<=300 ; j++)
				    dp[i][j] = min(dp[i][j], dp[i - a][j - b] + 1);
		}
		
        int ans = 1e9;
		for(int i=0 ; i<=300 ; i++)
            for(int j=0 ; j<=300 ; j++)
			    if (i * i + j * j == S*S) 
			        ans = min(ans, dp[i][j]);
		
		if (ans == 1e9) 
		    cout << "not possible\n";
		else 
		    cout << ans << "\n";
    }   
    return 0;
}
