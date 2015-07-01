#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct bignum
{
	int digit[3000];
	int size;
	bignum ()
	{
		memset(digit,0,sizeof(digit));
		size=1;
	}
};
bignum multi(bignum pre,int n);
void carry(bignum &cur);
void print_num(bignum num);
bignum dp[1001];

int main()
{
	ios::sync_with_stdio(0);
	dp[0].digit[0]=1;
	dp[0].size=1;
	dp[1].digit[0]=1;
	dp[1].size=1;
	for(int i=2 ; i<=1000 ; i++)
	{
		dp[i]=multi(dp[i-1],i);
	}
	int n;
	while(cin>>n)
	{
		cout<<n<<"!\n";
		print_num(dp[n]);
		cout<<'\n';
	}
	return 0;
}

bignum multi(bignum pre,int n)
{
	for(int m=0 ; m<pre.size ; m++)
	{
		pre.digit[m]*=n;
	}
	int i=0;
	while(1)
	{
		if(pre.digit[i]>9)
		{
			pre.digit[i+1]+=pre.digit[i]/10;
			pre.digit[i]%=10;
		}
		i++;
		if(pre.size+1<i &&pre.digit[i]<10)
			break;
		
	}
	pre.size=i+1;
	return pre;
}

void print_num(bignum num)
{
	bool p=0;
	for(int i=num.size-1 ; i>=0 ; i--)
	{
		if(num.digit[i]!=0)p=1;
		if(p)cout<<num.digit[i];
	}
}
