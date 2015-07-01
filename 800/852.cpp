#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int b,w,sum;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void print_mp(char m[20][20])
{
	for(int i=0;i<9;i++)
	{	for(int j=0;j<9;j++)
		{
			cout<<m[i][j];
		}cout<<'\n';
	}
}

void dfs_fload(char m[20][20],int x,int y)
{
	if(x>=0 && x<9 && y>=0 && y<9)
	{
		if(m[x][y]=='X')b++;
		else if(m[x][y]=='O')w++;
		else
		{
			if(m[x][y]=='.')
			{
				m[x][y]='*';
				sum++;
				for(int i=0;i<4;i++)
					dfs_fload(m,x+dx[i],y+dy[i]);
			}
		}
	}
}

int main()
{
	int num;
	cin>>num;
	char mp[20][20];
	for(int i=0 ; i<num ; i++)
	{
		for(int k=0 ; k<9 ; k++)
			for(int j=0 ; j<9 ; j++)
				cin>>mp[k][j];
		//print_mp(mp);
		int black=0,white=0;
		for(int k=0 ; k<9 ; k++)
		{
			for(int j=0 ; j<9 ; j++)
			{
				if(mp[k][j]=='O')
				{
					white++;
				}
				else if(mp[k][j]=='X')
				{
					black++;
				}
				else if(mp[k][j]=='.')
				{
					sum=0,b=0,w=0;
					dfs_fload(mp,k,j);
					if(!w)black+=sum; 
					else if(!b)white+=sum;
				}
			}
		}
		cout<<"Black "<<black<<" White "<<white<<'\n';
	}
	return 0;
}
