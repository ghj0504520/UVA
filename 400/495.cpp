#include <iostream>
#include <cstring>
using namespace std;
struct bignum
{
	int digit[2000];
	bignum()
	{
		memset(digit,0,sizeof(digit));
	}
}dp[5010];

void print(bignum curnum)
{
	bool start=0;
	for(int i=1999 ; i>=0 ; i--)
	{
		if(!start&&curnum.digit[i])
		{
			start=1;
		}
		if(start)
		{
			cout<<curnum.digit[i];
		}
	}
	cout<<"\n";
}
int main()
{
	dp[0].digit[0]=0;
	dp[1].digit[0]=1;
	for(int i=2 ; i<=5000 ; i++)
	{
		for(int j=0 ; j<2000-1 ; j++)
		{
			dp[i].digit[j]+=dp[i-2].digit[j]+dp[i-1].digit[j];
			dp[ i ].digit[ j+1 ]+=dp[ i ].digit[ j ]/10;
			dp[ i ].digit[ j ]%=10;
		}
	}
	
	int q;
	while(cin>>q)
	{
		if(!q)cout<<"The Fibonacci number for "<<q<<" is 0\n";
		else
		{
			cout<<"The Fibonacci number for "<<q<<" is ";
			print(dp[q]);
		}
	}
	return 0;
}