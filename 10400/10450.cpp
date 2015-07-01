#include <iostream>

using namespace std;

int main()
{
	long long dp[60]={0};
	dp[0]=0;
	dp[1]=2;
	dp[2]=3;
	for(int i=3 ; i<60 ; i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}
	int n;
	cin>>n;
	for(int i=0 ; i<n ; i++)
	{
		
		int query;
		cin>>query;
		cout<<"Scenario #"<<i+1<<":\n";
		cout<<dp[query]<<"\n\n";
	}
	return 0;
}
