#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int coin[5]={1,5,10,25,50};
long long dp[30010];
void init_dp()
{
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=0 ; i<5 ; i++)
	{
		for(int j=coin[i]; j<30001 ; j++)
		{
			dp[j]=dp[j]+dp[j-coin[i]];
		}
	}
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
	init_dp();
	int q;
	while(cin>>q)
	{
		if(dp[q]==1)
			cout<<"There is only 1 way to produce "<<q<<" cents change.\n";
		else
			cout<<"There are "<<dp[q]<<" ways to produce "<<q<<" cents change.\n";
	}
	return 0;
}