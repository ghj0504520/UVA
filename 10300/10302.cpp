#include<iostream>
using namespace std;
int main()
{
	long long read;
	while(cin>>read)
	{
		long long sum=0;
		for(long long i=1;i<=read;i++)
			sum+=i;
		sum*=sum;
		cout<<sum<<'\n';
	}


}

