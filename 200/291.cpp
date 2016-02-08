#include <iostream>
#include <vector>

using namespace std;

int Edge[6][6];
int vis[6]={0};
string ans;

void init()
{
	for(int i=1 ; i<=5 ; i++)
		for(int j=1 ; j<=5 ; j++)
			if(i!=j)
				Edge[i][j]=1;
	Edge[1][4]=Edge[2][4]=Edge[4][1]=Edge[4][2]=0;

	ans.resize(9);
}

void DFS(int cur,int cnt)
{
	if(cnt>=8)
	{
		ans[8]=cur+'0';
		ans[9]='\0';
		cout<<ans<<"\n";
		return ;
	}
	
	for(int i=1 ; i<=5 ; i++)
	{
		if(Edge[cur][i])
		{	
			Edge[cur][i]=Edge[i][cur]=0;
			ans[cnt]=(char)(cur+'0');
			DFS(i,cnt+1);
			Edge[cur][i]=Edge[i][cur]=1;
		}	
	}
}

int main()
{
	init();
	DFS(1,0);
	return 0;
}