#include <iostream>
#include <cstring>

using namespace std;
struct bignum
{
	int digit[3000];
	int size;
	bignum ()
	{
		memset(digit,0,sizeof(digit));
		size=0;
	}
}dp[1001];

bignum addition(bignum n1,bignum n2,bignum n3)
{
	int i;
	bignum n4;
	for(i=0 ; i<n1.size || i<n2.size || i<n3.size ; i++)
	{
		n4.digit[i]=n1.digit[i]+n1.digit[i]+n2.digit[i]+n3.digit[i];
	}n4.size=i;
	for(i=0 ; i<n4.size+3 ; i++)
	{
		if(n4.digit[i]>9)
		{
			n4.digit[i+1]+=n4.digit[i]/10;
			n4.digit[i]%=10;
		}
	}n4.size=i;
	for(i=n4.size ; i>=0 ; i--)
	{
		if(n4.digit[i-1]!=0)break;
		n4.size--;
	}
	return n4;
}
void print_big(bignum p)
{
	for(int i=p.size-1 ; i>=0 ; i--)
	{
		cout<<p.digit[i];
	}cout<<'\n';
}
int main()
{
	dp[0].digit[0]=1;
	dp[0].size=1;
	dp[1].digit[0]=2;
	dp[1].size=1;
	dp[2].digit[0]=5;
	dp[2].size=1;
	dp[3].digit[0]=3;
	dp[3].digit[1]=1;
	dp[3].size=2;
	
	for(int i= 4 ; i<=1000 ; i++)
		dp[i]=addition(dp[i-1],dp[i-2],dp[i-3]);
	int q;
	while(cin>>q)
	{
		print_big(dp[q]);
	}
	return 0;
}
