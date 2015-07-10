#include <iostream>
#define MOD 1000000007
using namespace std;

long long bigmod(long long cur_power)
{
	if(!cur_power)
		return 1;
	else if(cur_power==1)
		return 2;
	else
	{
		long long r = bigmod( cur_power/2 );
		if(cur_power%2)
			return (2*r*r)%MOD;
		else
			return (r*r)%MOD;

	}
}
int main()
{
	ios::sync_with_stdio(0);
	int num;
	cin>>num;
	for (int i = 0; i < num; ++i)
	{
		long long q;
		cin>>q;
		cout<<"Case #"<<1+i<<": "<<((q%MOD)*bigmod(q-1))%MOD<<"\n";

	}
	return 0;
}

//∑C ( n , k ) * k = n * ∑C ( n-1 , k-1 )
//∑C（n-1,k-1）= 2^( n-1 )