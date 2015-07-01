#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int h[15][15],v[15][15],count[15];

int main()
{
	int dot,side,t=0;
	while(cin>>dot)
	{
		cin>>side;
		int s,mv;
		char c;
		memset(h,0,sizeof(h));
		memset(v,0,sizeof(v));
		memset(count,0,sizeof(count));
		
		for(int i=0 ; i<side ; i++)
		{
			cin>>c>>s>>mv;
			if(c=='H')
				h[s][mv]=1;
			else
				v[mv][s]=1;
		}
														//Brute Force
		for(int side_len=1 ; side_len<dot ; side_len++)                       
		{
			for(int x=1 ; x<=dot-side_len ; x++)
			{
				for(int y=1 ; y<=dot-side_len ; y++)
				{
					bool p=1;
					for(int len=0 ; len<side_len ; len++)
					{
						if(!p)	break;
						
						if(!h[x][y+len]) p=0;
						
						if(!h[x+side_len][y+len]) p=0;
						
						if(!v[x+len][y]) p=0;
						
						if(!v[x+len][y+side_len]) p=0;
					}
					if(p)	count[side_len]++;
				}
			}
		}
		
		if(t)cout<<"\n**********************************\n\n";
		cout<<"Problem #"<<++t<<"\n\n";
		bool p=0;
		for(int i=1 ; i<15 ; i++)
		{
			if(count[i])
			{
				p=1;
				cout<<count[i]<<" square (s) of size "<<i<<'\n';
			}
		}
		if(!p)
		{
			cout<<"No completed squares can be found.\n";
		}
	}
	return 0;
}
