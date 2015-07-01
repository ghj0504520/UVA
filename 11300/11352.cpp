#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int horse[8][2]={{1,2},{2,1},{-1,2},{-2,1},{1,-2},{2,-1},{-1,-2},{-2,-1}};
const int king[8][2]={{1,1},{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
char mp[150][150];
int x,y;
struct node
{
	int x,y,step;
	node (int ix,int iy,int is)
	{
		x=ix,y=iy,step=is;
	}
};

bool check_bound(int curX,int curY)
{
	if(curX>=0 && curX<x && curY>=0 && curY<y)
		return 1;
	return 0;
}

void print(char m[150][150])					//for debug
{
	for(int i=0 ; i<x ; i++)
	{
		for(int j=0 ; j<y ; j++)
		{
			cout<<m[i][j]<<' ';
		}cout<<'\n';
	}
}

int bfs(queue<node> BFS)
{
	while(!BFS.empty())
	{
		node cur=BFS.front();
		BFS.pop();
		int mx,my;
		for(int m=0 ; m<8 ; m++)
		{
			mx=cur.x+king[m][0];
			my=cur.y+king[m][1];
			if(mp[mx][my]=='B')
				return cur.step+1;
			else if(check_bound(mx,my) &&mp[mx][my]=='.')
			{
				mp[mx][my]='#';
				BFS.push(node(mx,my,cur.step+1));
			}
			
		}
	}
	return -1;
}

void init(queue<node> &BFS)
{
	for(int i=0 ; i<x ; i++)
	{
		for(int j=0 ; j<y ; j++)
		{
			if(mp[i][j]=='A')
				BFS.push(node(i,j,0));
			else if(mp[i][j]=='Z')
			{
				mp[i][j]='#';
				for(int m=0 ; m<8 ; m++)
				{
					int mx=i+horse[m][0],my=j+horse[m][1];
					if(check_bound(mx,my)&&mp[mx][my]=='.')
						mp[mx][my]='#';
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	while(n--)
	{
		cin>>x>>y;
		queue<node> BFS;
		memset(mp,0,sizeof(mp));
		for(int i=0 ; i<x ; i++)
			cin>>mp[i];
		init(BFS);
		int check=bfs(BFS);
		if(check==-1)
			cout<<"King Peter, you can't go now!\n";
		else
			cout<<"Minimal possible length of a trip is "<<check<<"\n";
	}
	return 0;
}
