#include <iostream>
#include <cmath>
using namespace std;

long long dp[1000001]={0};
int main()
{
	
	dp[0]=1;
	for(int i=1 ; i<=1000000 ; i++)
	{
		int n1,n2,n3;
		n1=(int)(i-sqrt(i));
		n2=(int)(log(i));
		n3=(int)(i*sin(i)*sin(i));
		dp[i]=(dp[n1]+dp[n2]+dp[n3])%1000000;
	}
	int q;
	while(cin>>q)
	{
		if(q==-1)break;
		else cout<<dp[q]<<'\n';
	}
	return 0;
}
