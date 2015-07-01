#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{

	int a,b,time=0;
	while(cin>>a>>b)
	{
		time++;
		if(a==0&&b==0)
			break;
		int d1[a],d2[b],dp[a+1][b+1];

		for(int i=0;i<a;i++)
			cin>>d1[i];
		for(int j=0;j<b;j++)
			cin>>d2[j];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(d1[i-1]==d2[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=max(dp[i][j-1],dp[i-1][j]);

			}		
		}cout<<"Twin Towers #"<<time<<"\nNumber of Tiles : "<<dp[a][b]<<"\n\n";

	}
}
