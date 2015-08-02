#include <iostream>
#include <cstring>
using namespace std;

bool prime[ 65010];

void init()
{
	memset(prime,0,sizeof(prime));
	prime[0]=1;
	prime[1]=1;
	for(int i=2 ; i<=65000 ; i++)
		if(!prime[i])
			for(int j=i+i ; j<=65000 ; j+=i)
				prime[j]=1;
}

long long bigmod(long long a,long long n,long long mod)
{
	if(n==0)return 1;
	else if(n==1)return a%mod;
	else
	{
		long long next=bigmod(a,n>>1,mod)%mod;
		if(n%2)	return (a*next*next)%mod;
		else	return (next*next)%mod;
	}
}

bool fermat(long long q)
{
	for(int i=2; i<q; i++)
	{
		if(bigmod(i,q,q)!=i)
			return 0;
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(0);
	long long q;
	init();
	while(cin>>q,q)
	{
		if(prime[q]&&fermat(q))
			cout<<"The number "<<q<<" is a Carmichael number.\n";
		else	cout<<q<<" is normal.\n";
	}
	return 0;
}
/*

if n is not prime 

&&

for each a =2~ (n-1) then  a^n mod n =a

*/