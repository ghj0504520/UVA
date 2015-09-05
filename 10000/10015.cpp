#include <iostream>
#include <vector>

using namespace std;

vector<int>Prime;
bool dp[100000]={0};
void sieve()
{
	dp[0]=1;
	dp[1]=1;
	dp[2]=0;
	for(int i=4;i<100000;i+=2)dp[i]=1;
	Prime.push_back(2);
	for(int i=3;i<100000 ;i+=2)
	{
		if(dp[i]==0)
		{
			Prime.push_back(i);
			for(int j=i+i ; j<100000 ; j+=i)
				dp[j]=1;
		}
	}
}


int main()
{
	sieve();
	int n;
	while(cin>>n,n)
	{
		int cur=n,remain=0;
		for(int k=2; k<=n; k++)
		{
			cur--;
			remain=(remain+Prime[cur-1])%k;
		}
		cout<<remain+1<<"\n";
	}
}