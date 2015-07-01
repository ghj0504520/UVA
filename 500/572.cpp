#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

void dfs(char mp[200][200],int x,int y,int r,int c)
{
	if(x>=0 && x<r && y>=0 && y<c && mp[x][y]=='@')
	{
		//cout<<1;
		mp[x][y]='*';
		dfs(mp,x+1,y,r,c);
		dfs(mp,x-1,y,r,c);
		dfs(mp,x,y+1,r,c);
		dfs(mp,x,y-1,r,c);
		
		dfs(mp,x+1,y+1,r,c);
		dfs(mp,x-1,y+1,r,c);
		dfs(mp,x+1,y-1,r,c);
		dfs(mp,x-1,y-1,r,c);
	}
}
int main()
{
	int r,c;
	while(cin>>r>>c)
	{
		if(!r&&!c)
			break;
		char mp[200][200];
		for(int i=0;i<r;i++)
			scanf("%s",mp[i]);
		
		int sum=0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(mp[i][j]=='@')
				{
					sum++;
					dfs(mp,i,j,r,c);
				}
			}
		}
		cout<<sum<<'\n';
	}
}
