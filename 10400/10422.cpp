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

int check()
{
	for(int i=0 ; i<5 ; i++)
		for(int j=0 ; j<5 ; j++)
			if(state[i][j]!=Fin_state[i][j])
				return 0;
	return 1;
}

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
	if(check())
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
			for(int j=0 ; j<5 ; j++)
			{
				ch=getchar();
				if(ch==' ')
				{
					state[i][j]=-1;
					start_x=i,start_y=j;
				}
				else
				{
					state[i][j]=ch-'0';
				}
			}
			getchar();
		}
		DFS(start_x,start_y,0);
		if(ans>10)cout<<"Unsolvable in less than 11 move(s).\n";
		else cout<<"Solvable in "<<ans<<" move(s).\n";
	}
	return 0;
}
