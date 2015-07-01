#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;
char mp[40][40][40];
struct node
{
	int x,y,z,step;
	node (int ix,int iy,int iz,int is)
	{
		x=ix,y=iy,z=iz,step=is;
	}
};
int dir[6][3]={{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};

int bfs(int sx,int sy,int sz,int l,int r,int c)
{
	queue<node> BFS;
	BFS.push(node(sx,sy,sz,0));
	mp[sx][sy][sz]='#';
	while(!BFS.empty())
	{
		node cur=BFS.front();
		BFS.pop();
		
		for(int i=0 ; i<6 ; i++)
		{
			node next(cur.x+dir[i][0],cur.y+dir[i][1],cur.z+dir[i][2],cur.step);
			
			if(next.x>=0&&next.x<l&&next.y>=0&&next.y<r&&next.z>=0&&next.z<c)
			{
				if(mp[next.x][next.y][next.z]!='#')
				{
					next.step++;
					if(mp[next.x][next.y][next.z]=='E')
					{
						return next.step;
					}
					mp[next.x][next.y][next.z]='#';
					BFS.push(next);
				}
			}
		}
	}
	return -1;
}
int main()
{
	int x,y,z;
	while(cin>>x>>y>>z)
	{
		if(!x && !y && !z)
			break;
		int sx,sy,sz;
		for(int i=0 ; i<x ; i++)
		{
			for(int j=0 ; j<y ; j++)
			{
				scanf("%s",mp[i][j]);
				for(int k=0 ; k<z ; k++)
				{
					if(mp[i][j][k]=='S')
					{
						sx=i,sy=j,sz=k;
					}
				}
			}
		}
		int check=bfs(sx,sy,sz,x,y,z);
		if(check==-1)
		{
			cout<<"Trapped!\n";
		}
		else
		{
			cout<<"Escaped in "<<check<<" minute(s).\n";
		}
	}
	return 0;
}
