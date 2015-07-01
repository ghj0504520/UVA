#include <iostream>
#include <cstdio>
#include <cmath>
#define esp 1e-6
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,pos,i=0;
		double p,ans=0.0,tmp;
		cin>>n>>p>>pos;
		do
		{
			tmp=pow(1-p,n*i+pos-1)*p;
			ans+=tmp;
			i++; 
		}while(tmp>esp);
		printf("%.4lf\n",ans);
	}
	return 0;
}
