#include <iostream>

using namespace std;

long long bigmod(long long power,long long mod)
{
	if(power==0)
		return 1;
	else if(power==1)
		return 2;
	else
	{
		long long next_value=bigmod(power/2,mod);
		if(power%2)
			return (2*next_value*next_value)%mod;
		else
			return (next_value*next_value)%mod;
	}
}
int main()
{
	long long q;
	while(cin>>q)
	{
		if(q==-1)break;
		cout<<q;
		bigmod(q-1,q)%q==1? cout<<" is a Jimmy-number\n" : cout<<" is not a Jimmy-number\n";
	}
	return 0;
}