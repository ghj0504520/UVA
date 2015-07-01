#include <iostream>

using namespace std;

int main()
{
	long long dp[90]={0};
	dp[0]=0;
	dp[1]=1,dp[2]=2;
	for(int i=3;i<90;i++)
		dp[i]=dp[i-1]+dp[i-2];
		
	int query;
	while(cin>>query,query)
	{
		cout<<dp[query]<<'\n';
	}
	return 0;
}
