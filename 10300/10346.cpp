#include<iostream>
using namespace std;
int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		int sum=0;
		sum+=n;
		while(n>=k)
		{
			int p=n/k;
			sum=sum+p;
			n%=k;
			n+=p;
		}cout<<sum<<'\n';
	}

}
