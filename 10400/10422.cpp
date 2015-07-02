//BFS code for c++ only ,c++11 cannot compile
/***BFS***/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <set>
using namespace std;

struct node
{
	int x,y;
	int st[5][5];
	int step;
	bool operator < (const node &pre)const
	{
		return memcmp(pre.st,this->st,sizeof(this->st)) < 0;
	}
};
int Fin_state[5][5] =	
{  
    {1, 1, 1, 1, 1},  
    {0, 1, 1, 1, 1},  
    {0, 0,-1, 1, 1},  
    {0, 0, 0, 0, 1},  
    {0, 0, 0, 0, 0}  
};

int h_mv[8][2]=
{
	{ 2, 1},
	{ 2,-1},
	{-2,-1},
	{ 1, 2},
	{ 1,-2},
	{-1,-2},
	{-1, 2},
	{-2, 1}
};
queue<node> bfs;
set<node> visit;

void init()
{
	while(!bfs.empty())
		bfs.pop();
	visit.clear();
}
bool bound(int x,int y)
{
	return x>=0&&x<5&&y>=0&&y<5? 1 : 0;
}
int hash(node p)
{
	if(visit.count(p))
		return 0;
	visit.insert(p);
	return 1;
}
void swap(int &p1,int &p2)
{
	int tmp=p1;
	p1=p2;
	p2=tmp;
}
void BFS(node p)
{
	init();
	bfs.push(p);
	node q;
	while(!bfs.empty())
	{
		p=bfs.front();
		bfs.pop();
		if(p.step>10)
		{
			cout<<"Unsolvable in less than 11 move(s).\n";
			return ;
		}
		if(!memcmp(p.st,Fin_state,sizeof(p.st)))
		{
			cout<<"Solvable in "<<p.step<<" move(s).\n";
			return ;
		}	
		for (int i = 0; i < 8; ++i)
		{
			q=p;
			q.x+=h_mv[i][0];
			q.y+=h_mv[i][1];
			q.step++;
			if(bound(q.x,q.y))
			{
				int tmp = q.st[p.x][p.y];
            				q.st[p.x][p.y] = q.st[q.x][q.y];
            				q.st[q.x][q.y] = tmp;
				if(hash(q))
				{
					bfs.push(q);
				}
			}
		}
	}
	return ;
}
int main(int argc, char const *argv[])
{
	int count;
	cin>>count;
	getchar();
	for (int t = 0; t < count; ++t)
	{
		node cur;
		for(int i=0 ; i<5 ; i++)
		{
			string in;
			getline(cin,in);
			for(int l=0 ; l<5 ; l++)
			{
				if(in[l]==' ')
				{
					cur.st[i][l]=-1;
					cur.x=i,cur.y=l;
				}
				else
				{
					cur.st[i][l]=in[l]-'0';
				}
			}
		}
		cur.step=0;
		BFS(cur);
	}
	return 0;
}


/***DFS***/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int Fin_state[5][5] =	
{  
    {1, 1, 1, 1, 1},  
    {0, 1, 1, 1, 1},  
    {0, 0,-1, 1, 1},  
    {0, 0, 0, 0, 1},  
    {0, 0, 0, 0, 0}  
};

int h_mv[8][2]=
{
	{ 2, 1},
	{ 2,-1},
	{-2,-1},
	{ 1, 2},
	{ 1,-2},
	{-1,-2},
	{-1, 2},
	{-2, 1}
};

int state[5][5],ans,t=0;

void swap(int &p1,int &p2)
{
	int tmp=p1;
	p1=p2;
	p2=tmp;
}

void DFS(int s_x,int s_y,int step)
{
	if(step>10)
		return ;
	if(!memcmp(state,Fin_state,sizeof(Fin_state)))
	{
		if(step<ans)
		{
			ans=step;
			return ;
		}
	}
	for(int i=0 ; i<8 ; i++)
	{
		int cur_x=h_mv[i][0]+s_x,cur_y=h_mv[i][1]+s_y;
		if(cur_x>=0&&cur_x<5&&cur_y>=0&&cur_y<5)
		{
			swap(state[s_x][s_y],state[cur_x][cur_y]);
			DFS(cur_x,cur_y,step+1);
			swap(state[s_x][s_y],state[cur_x][cur_y]);
		}
	}
		
}
int main()
{
	
	int t;
	cin>>t;
	getchar();
	while(t--)
	{
		ans=0xfff;
		memset(state,0,sizeof(state));
		char ch;
		int start_x,start_y;
		for(int i=0 ; i<5 ; i++)
		{
			string in;
			getline(cin,in);
			for(int l=0 ; l<5 ; l++)
			{
				if(in[l]==' ')
				{
					state[i][l]=-1;
					start_x=i,start_y=l;
				}
				else
				{
					state[i][l]=in[l]-'0';
				}
			}
		}
		DFS(start_x,start_y,0);
		if(ans>10)cout<<"Unsolvable in less than 11 move(s).\n";
		else cout<<"Solvable in "<<ans<<" move(s).\n";
	}
	return 0;
}