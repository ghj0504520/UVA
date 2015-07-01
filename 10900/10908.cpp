#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int t;
	cin>>t;
	char mp[150][150];
	while(t--)
	{
		int x,y,q;
		cin>>x>>y>>q;
		for(int i=0 ; i<x ; i++)
			cin>>mp[i];
		cout<<x<<" "<<y<<" "<<q<<"\n";
		
		int qx,qy,ans=1;
		while(q--)
		{
			cin>>qx>>qy;
			ans=1;
			for(int len=1 ; ; len++)
			{
				bool check=1;
				for(int mx=qx-len ; mx<=qx+len ; mx++)
				{
					for(int my=qy-len ; my<=qy+len ; my++)
					{
						if(mx<0 || my<0 || mx>=x || my>=y || mp[mx][my]!=mp[qx][qy])
						{
							check=0;
							break;
						}
					}
					if(!check)break;
				}
				if(!check)break;
		
				ans+=2;
			}
			cout<<ans<<'\n';

		}
		
	}
	return 0;
}
