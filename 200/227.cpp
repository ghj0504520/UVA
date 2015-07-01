#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	char mp[5][6],cmd[100];
	int t=0;
	while(cin.getline(mp[0],6))
	{
		if(!strcmp(mp[0],"Z"))
			break;
		for(int i=1;i<5;i++)
			cin.getline(mp[i],6);
		if(t)cout<<'\n';
		cout<<"Puzzle #"<<++t<<":\n";
		int x,y;
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				if(mp[i][j]==' '||mp[i][j]=='\0')
					x=i,y=j;
			}
		}
		bool out=0,error=0;
		while(cin.getline(cmd,99))
		{
			int len=strlen(cmd);
			for(int i=0;i<len;i++)
			{
				if(cmd[i]=='0')
				{
					out=1;
					break;
				}
				else if(cmd[i]=='A' && !error)
				{
					if(x==0)
					{
						error=1;
						//break;
					}
					mp[x][y]=mp[x-1][y];
					x--;
				}
				else if(cmd[i]=='B' && !error)
				{
					if(x==4)
					{
						error=1;
						//break;
					}
					mp[x][y]=mp[x+1][y];
					x++;
				}
				else if(cmd[i]=='L' && !error)
				{
					if(y==0)
					{
						error=1;
						//break;
					}
					mp[x][y]=mp[x][y-1];
					y--;
				}
				else if(cmd[i]=='R' && !error)
				{
					if(y==4)
					{
						error=1;
						//break;
					}
					mp[x][y]=mp[x][y+1];
					y++;
				}
			}
			if(out)break;
		}
		if(error)
			cout<<"This puzzle has no final configuration.\n";
		else
		{
			for(int i=0;i<5;i++)
			{
				for(int j=0;j<5;j++)
				{
					if(j)cout<<" ";
					if(i==x&j==y)
					{
						cout<<" ";
					}
					else
					{
						cout<<mp[i][j];
					}
				}cout<<'\n';
			}
		}
		memset(mp,0,sizeof(mp));
	}
}
