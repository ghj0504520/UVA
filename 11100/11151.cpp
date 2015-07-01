#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int ans;

void lcs_dp(string o,string r,int len)
{
	int dp[1010][1010];
	memset(dp,0,sizeof(dp));
	
	for(int i=1;i<=len;i++)
	{
		for(int j=1;j<=len;j++)
		{
			if(o[i]==r[j])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	ans=dp[len][len];
}

void reverse(string s,int len)
{
	string o,r;
	o="0";
	o+=s;
	r="0";
	for(int i=len-1 ; i>=0 ; i--)
	{
		r+=s[i];
	}
	lcs_dp(o,r,len);
}

int main()
{
	int num;
	cin>>num;
	getchar();
	string seq;
	for(int i=0 ; i<num ; i++)
	{
		getline(cin,seq);
		ans=0;
		int len=seq.length();
		reverse(seq,len);
		cout<<ans<<'\n';;
	}
	return 0;
}
