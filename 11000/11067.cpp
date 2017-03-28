#include <iostream>

using namespace std;

int main()
{
	int w,h;
	while(cin>>w>>h)
	{
		if(!w&&!h)break;

		int n;
		cin>>n;
		int m[150][150]={0};
		for(int i=0 ; i<n ; i++)
		{
			int x,y;
			cin>>x>>y;
			m[h-y][x]=-1;
		}

		long long dp[150][150]={0};
		dp[h][0]=1;
		for(int i=h ; i>=0 ; i--)
		{
			for(int j=0 ; j<=w ; j++)
			{
				if(j-1>=0&&m[i][j-1]!=-1)
					dp[i][j]+=dp[i][j-1];
				if(i+1>=0&&m[i+1][j]!=-1)
					dp[i][j]+=dp[i+1][j];
			}
		}
		
		if(dp[0][w]==0)
		{
			cout<<"There is no path.\n";
		}else if(dp[0][w]==1)
		{
			cout<<"There is one path from Little Red Riding Hood's house to her grandmother's house.\n";
		}else
		{
			cout<<"There are "<<dp[0][w]<<" paths from Little Red Riding Hood's house to her grandmother's house.\n";
		}

	}
	return 0;
}