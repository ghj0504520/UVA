#include <cstring>
#include <iostream>

using namespace std;

int coin[5]={1,5,10,25,50};
long long dp[7500];

void init_dp()
{
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=0 ; i<5 ; i++)
	{
		for(int j=coin[i] ; j<7500 ; j++)
		{
			dp[j]=dp[j]+dp[j -coin[i] ];
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	init_dp();
	int q;
	while(cin>>q)
	{
		cout<<dp[q]<<"\n";
	}
}