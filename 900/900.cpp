#include <iostream>

using namespace std;

int main()
{
	long long dp[60]={0};
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	for(int i=3 ; i<60 ; i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}
	int num;
	while(cin>>num,num)
	{
		cout<<dp[num]<<'\n';
	}
	return 0;
}
