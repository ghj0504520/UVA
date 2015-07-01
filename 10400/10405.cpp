#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	string read1,read2;
	while(getline(cin,read1))
	{
		getline(cin,read2);
		int len1=read1.length(),len2=read2.length();
		int dp[len1+1][len2+1];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=len1;i++)
		{
			for(int j=1;j<=len2;j++)
			{
				if(read1[i-1]==read2[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);

			}
		}cout<<dp[len1][len2]<<"\n";
	}
}
