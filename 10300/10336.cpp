#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int sum;
struct Count
{
	char alpha;
	int num;
};

bool cmp(const Count &i,const Count &j)
{
	return i.num>j.num || (i.num==j.num && i.alpha <j.alpha);
}

void print_mp(char mp[1000][1000],int r,int c)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<mp[i][j];
		}cout<<'\n';
	}
}

int dfs_x[]={-1,0,1,0};
int dfs_y[]={0,-1,0,1};
void dfs_fload(char mp[1000][1000],const char now,int x,int y,const int r,const int c)
{
	if(x>=0 && x<r && y>=0 && y<c && mp[x][y]==now)
	{
		mp[x][y]='*';
		for(int i=0;i<4;i++)
			dfs_fload(mp,now,x+dfs_x[i],y+dfs_y[i],r,c);
	}
}

int main()
{
	int num,r,c;
	cin>>num;
	for(int t=0 ; t<num ; t++)
	{
		cout<<"World #"<<t+1<<"\n";
		cin>>r>>c;
		char mp[1000][1000];                         //initialize map and read in
		memset(mp,0,sizeof(mp));
		for(int i=0;i<r;i++)          
		{
			for(int j=0;j<c;j++)
			{
				cin>>mp[i][j];
			}
		}
		Count data[128];
		for(int i=0;i<128;i++)
		{
			data[i].alpha=(char)i;
			data[i].num=0;
		}
		for(int i=0;i<r;i++)                         //traversal map by DFS
		{
			for(int j=0;j<c;j++)
			{
				if(mp[i][j]!='*')
				{
					char cur=mp[i][j];
					dfs_fload(mp,cur,i,j,r,c);
					data[(int)cur].num++;
				}
			}
		}
		sort(data,data+128,cmp);                      //sort and print each none zero value
		for(int i=0;i<=30;i++)
		{
			if(data[i].num)
			{
				cout<<data[i].alpha<<": ";
				cout<<data[i].num<<'\n';
			}
		}
	}
	return 0;
}
