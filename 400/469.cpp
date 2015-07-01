#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int ans;
void dfs_fload(char mp[200][200],char use[200][200],int x,int y)
{
	if(!(x<0 || y<0 || mp[x][y]==0 || mp[x][y]!='W' || use[x][y]))      //branch for DFS
	{
		use[x][y]=1;
		ans++;
		
		for(int i=-1;i<=1;i++)
			for(int j=-1;j<=1;j++)
				dfs_fload(mp,use,x+i,y+j);
	}
}
int main()
{
	int num;
	cin>>num;
	getchar();
	getchar();
	int t;
	for(t=0;t<num;t++)
	{
		int n=0;
		if(t)cout<<'\n';
		char tmp[200],mp[200][200],used[200][200];
		memset(mp,0,sizeof(mp));
		while(cin.getline(tmp,200))                                   //figure out for I/O
		{
			if(!strlen(tmp))break;
			
			if(tmp[0]!='W'&&tmp[0]!='L')
			{
				int x,y;
				sscanf(tmp,"%d %d",&x,&y);
				memset(used,0,sizeof(used));
				ans=0;
				dfs_fload(mp,used,x-1,y-1);
				cout<<ans<<'\n';
			}
			else
			{
				sscanf(tmp,"%s",mp[n++]);
			}
		}
	}
	return 0;
}
