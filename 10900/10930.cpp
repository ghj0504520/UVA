#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int dp[1500];
	int t,r=0;
	while(cin>>t)
	{
		memset(dp,0,sizeof(dp));
		int num[t];
		for(int i=0 ; i<t ; i++)
			cin>>num[i];
		
		dp[0]=1;
		for(int i=0 ; i<t ; i++)
		{
			for(int j=1000 ; j>=0 ; j--)
			{
				if(dp[j] && num[i]+j<=1000)
				{
					dp[j+num[i]]++;
				}
			}
		}
		
		bool check=1;
		if(num[0]<1)check=0;
		for(int i=0 ; i<t-1 ; i++)
		{
			if(num[i]>num[i+1])
			{
				check=0;
				break;
			}
			if(dp[num[i]]>1)
			{
				check=0;
				break;
			}
		}
		if(dp[num[t-1]]>1)
		{
			check=0;
		}
		
		cout<<"Case #"<<++r<<":";
		for(int i=0 ; i<t ;i++)
			cout<<" "<<num[i];
		cout<<'\n';
		if(check)cout<<"This is an A-sequence.\n";
		else cout<<"This is not an A-sequence.\n";
	}
	return 0;
}
