#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int g,b;
	while(cin>>g>>b)
	{
		int p[1000000]={0};
		for(int i=0;i<b;i++)
		{	
			int n;
			cin>>n;
			p[n-1]=1;
		}
		bool out=0;
		if(g==b)
		{
			cout<<"*\n";
		}
		else
		{
			for(int i=0;i<g;i++)
			{
				if(!p[i])
				{
					cout<<i+1<<' ';
					out=1;
				}
			}
			cout<<'\n';
		}
	}
	return 0;
}
