#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long int n;
	cin>>n;
	for(int t=0 ; t<n ; t++)
	{
		long long int x,k;
		cin>>x>>k;
		long double c=ceil((long double)x/k),f=floor((long double)x/k);
		
		long long int C=c,F=f,i;
		for(i=0 ; i<=k ; i++)
		{
			if(x-i*F==(k-i)*C)
			{
				break;
			}
		}
		cout<<i<<' '<<k-i<<'\n';
	}
	return 0;
}
