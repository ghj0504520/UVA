#include <iostream>
#include <cstring>
using namespace std;

bool p[1000000+10];

int reverse(int q)
{
	int sum=0;
	while(q)
	{
		sum=sum*10+q%10;
		q/=10;
	}
	return sum;
}

int main()
{
	memset(p,0,sizeof(p));
	p[0]=1;
	p[1]=1;
	for(int i=2 ; i<=1000000 ; i++)
	{
		for(int j=i+i ; j<=1000000 ; j+=i)
		{
			p[j]=1;
		}
	}
	int query;
	while(cin>>query)
	{
		int rev;
		rev=reverse(query);
		if(p[query])
		{
			cout<<query<<" is not prime.\n";
		}
		else
		{
			if(!p[rev] &&rev!=query)
				cout<<query<<" is emirp.\n";
			else
				cout<<query<<" is prime.\n";
		}
	}
	return 0;
}
