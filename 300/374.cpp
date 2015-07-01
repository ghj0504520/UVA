#include <iostream>
#include <cmath>

using namespace std;

long long bigModSimulate(long long int cur_b,long long int cur_p,long long int cur_m)
{
	if(!cur_p)										//figure out
		return 1;
	else if(cur_p==1)	
		return cur_b%cur_m;
	else
	{
		long long r=bigModSimulate(cur_b,cur_p/2,cur_m);
		if(cur_p%2)
			return (cur_b*r*r)%cur_m;
		else
			return (r*r)%cur_m;
	} 
}

int main()
{
	long long int b,p,m;
	while(cin>>b>>p>>m)
		cout<<bigModSimulate(b,p,m)<<"\n";
	return 0;
}
