#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

string name;
int sX,sY,eX,eY;
char sD;
vector<int>graph[15][15][4];
int convert(char c)
{
	switch(c)
	{
		case 'N':return 0;
		case 'E':return 1;
		case 'S':return 2;
		case 'W':return 3;
		case 'F':return 0;
		case 'L':return -1;
		case 'R':return 1;
	}
}


int vis[15][15][4];
int move[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
struct node
{
	int X,Y,Dir;
	node(){}
	node(int x,int y,int d)
	{
		X=x,Y=y,Dir=d;
	}
	bool operator<(const node &f)const
	{
		return X<f.X ||(X==f.X&&Y<f.Y) ||(X==f.X&&Y==f.Y&&Dir<f.Dir);
	}
};
map<node,node> Trace;
vector<node>ANS;
bool check(node cur)
{
	return (cur.X<=9 && cur.Y<=9 && cur.X>=1 && cur.Y>=1)? 1:0;
}
void getPath(node u)
{	
	while(1)
	{
		ANS.push_back(u);
		if(!vis[u.X][u.Y][u.Dir])break;
		u=Trace[u];
	}
	int len=ANS.size(),t=1;
	cout<<name<<"\n ";
	cout<<" ("<<sX<<","<<sY<<")";
	for(int i=len-1 ; i>=0 ; i--)
	{
		if((t++)%10==0)cout<<"\n ";
		cout<<" ("<<ANS[i].X<<","<<ANS[i].Y<<")";
	}
	cout<<"\n";
}

void BFS()
{
	int sDir=convert(sD);
	node s(sX,sY,sDir);
	node next(sX+move[sDir][0],sY+move[sDir][1],sDir);
	Trace[next]=s;

	queue<node>bfs;
	bfs.push(next);
	vis[next.X][next.Y][next.Dir]=0;
	while(!bfs.empty())
	{
		node cur=bfs.front();
		bfs.pop();
		if(cur.X==eX&&cur.Y==eY)
		{
			getPath(cur);
			return ;
		}
		int len=graph[cur.X][cur.Y][cur.Dir].size();
		for(int i=0 ; i<len ; i++)
		{
			int newD=(graph[cur.X][cur.Y][cur.Dir][i]+cur.Dir+4)%4;

			node newCur(cur.X+move[newD][0],cur.Y+move[newD][1],newD);
			if(check(newCur) && vis[newCur.X][newCur.Y][newCur.Dir]<0)
			{
				vis[newCur.X][newCur.Y][newCur.Dir]=vis[cur.X][cur.Y][cur.Dir]+1;
				bfs.push(newCur);
				Trace[newCur]=cur;	
			}
		}
	}
	cout<<name<<"\n  No Solution Possible\n";
}
void Clear()
{
	Trace.clear();
	ANS.clear();
	for(int i=0 ; i<15 ; i++)
		for(int j=0 ; j<15 ; j++)
			for(int k=0 ; k<4 ; k++)
			{
				vis[i][j][k]=-1;
				graph[i][j][k].clear();
			}
}

int main()
{
	ios::sync_with_stdio(0);
	while(getline(cin,name))
	{
		if(name=="END")break;
		Clear();

		cin>>sX>>sY>>sD>>eX>>eY;
		int x,y;
		string cmd;
		while(cin>>x,x)
		{
			cin>>y;
			while(cin>>cmd)
			{
				if(cmd=="*")break;
				int len=cmd.size();
				int dir=convert(cmd[0]);
				for(int i=1 ; i<len ; i++)
					graph[x][y][dir].push_back(convert(cmd[i]));
			}
		}
		BFS();
		cin.ignore();
	}
	return 0;
}