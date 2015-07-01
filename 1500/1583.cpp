#include <iostream>

using namespace std;

int main()
{
	int dp[100005]={0};
	for(int i=1;i<100005;i++)
	{
		int origin=i,generate=i,sum=i;
		while(origin>0)
		{
			sum+=origin%10;
			origin/=10;
		}
		if(!dp[sum])dp[sum]=generate;
	}

	int num;
	cin>>num;
	for(int i=0;i<num;i++)
	{
		int query;
		cin>>query;
		cout<<dp[query]<<'\n';
	}
	return 0;
}
