#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int dp[500000+10]={0};
	dp[0]=0;
	dp[1]=1;
	for(int power=2,value=2,i=2;i<=500000;i++)
	{
		dp[i]=value;
		value+=2;
		if(i==power)
		{
			power*=2;
			value=2;
		}
	}
	int num;
	while(cin>>num,num)
	{
		cout<<dp[num]<<"\n";
	}
	return 0;
}