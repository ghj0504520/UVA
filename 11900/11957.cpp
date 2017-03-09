#include <iostream>
#include <cstring>

using namespace std;

char m[120][120];
int dp[120][120];

bool checkbound(int x,int y,int d)
{
	return x>=0&&x<d&&y>=0&&y<d;
}

int DP(int d)
{
	for(int i=d-1 ; i>=0 ; i--)
	{
		for(int j=0 ; j<d ; j++)
		{
			if(m[i][j]=='W')
				dp[i][j]=1;

			if( checkbound(i+1,j+1,d) && m[i+1][j+1]!='B')
				dp[i][j]+=dp[i+1][j+1];

			if( checkbound(i+1,j-1,d) && m[i+1][j-1]!='B')
				dp[i][j]+=dp[i+1][j-1];

			if( checkbound(i+1,j+1,d) && m[i+1][j+1]=='B')
				if( checkbound(i+2,j+2,d) && m[i+2][j+2]!='B')
					dp[i][j]+=dp[i+2][j+2];

			if( checkbound(i+1,j-1,d) && m[i+1][j-1]=='B')
				if( checkbound(i+2,j-2,d) && m[i+2][j-2]!='B')
				dp[i][j]+=dp[i+2][j-2];

			dp[i][j]%=1000007;
		}
	}
}

int main()
{
	int T;
	cin>>T;
	for(int t=0 ; t<T ; t++)
	{
		int d;
		cin>>d;
		
		memset(m,0,sizeof(m));
		memset(dp,0,sizeof(dp));

		for(int i=0 ; i<d ; i++)
			cin>>m[i];
		
		DP(d);

		int ans=0;
		for(int i=0 ; i<d ; i++)
		{
			if(m[0][i]!='B')
				ans+=dp[0][i];
			ans%=1000007;
		}
		cout<<"Case "<<t+1<<": "<<ans<<'\n';
	}
	return 0;
}