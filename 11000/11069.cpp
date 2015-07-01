#include <iostream>

using namespace std;

int main()
{
	long long dp[80]={0};
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	dp[3]=2;
	for(int i=4;i<80;i++)
		dp[i]=dp[i-2]+dp[i-3];
	
	int query;
	while(cin>>query)
	{
		cout<<dp[query]<<'\n';
	}
	return 0;
}
