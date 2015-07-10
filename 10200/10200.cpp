#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

bool prime[10001];

bool isPrime(int num)
{
	int fin=sqrt(num);
	for (int i = 2; i <=fin ; ++i)
	{
		if(num%i==0)
			return 0;
	}
	return 1;
}
void init()
{
	memset(prime,0,sizeof(prime));
	for(int i=0 ; i<=10000 ; i++)
	{
		if(isPrime(i*i+i+41))
			prime[i]=1;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	init();
	int a,b;
	while(cin>>a>>b)
	{
		int ans=0;
		for(int i=a ; i<=b ; i++)
		{
			if(prime[i])
				ans++;
		}
		printf("%.2lf\n", 100.0*ans/(b-a+1)+1e-5);
	}
	return 0;
}