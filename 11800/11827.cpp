#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int gcd(int a,int b)
{
	int r=a%b;
	while(r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
int main()
{
	int t;
	cin>>t;
	getchar();
	while(t--)
	{
		char line[200000],*ptr=line;
		cin.getline(line,200000);
		int num[200],mv,pos=0;
		while(sscanf(ptr,"%d%n",&num[pos],&mv)==1)
		{
			pos++;
			ptr+=mv;
		}
		sort(num,num+pos);
		int ans=0,tmp;
		for(int i=0 ; i<pos ; i++)
		{
			for(int j=i+1 ; j<pos ; j++)
			{
				tmp=gcd(num[j],num[i]);
				ans=max(ans,tmp);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
