#include <iostream>
#include <map>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int BFS(int S,int D,vector<int> N[])
{
	int step=0;
	queue<int>bfs;
	map<int,int>check;
	bfs.push(S);
	check.insert(std::pair<int,int>(S,step));
	while(!bfs.empty())
	{
		int cur=bfs.front();
		bfs.pop();
		step=check[cur];
		if(cur==D)	break;
		for(int i=0 ; i<N[cur].size() ; i++)
		{
			int now=N[cur][i];
			if(check.find(now)==check.end())
			{
				bfs.push(now);
				check.insert(std::pair<int,int>(now,step+1));
			}
		}
	}
	return step;
}
int main()
{
	int num,t=0;
	while(scanf("%d",&num)!=EOF)
	{
		printf("Test Set #%d\n",++t );
		vector<int> node[21];
		int v;
		for(int i=0 ; i<num ; i++)
		{
			scanf("%d",&v);
			node[1].push_back(v);
			node[v].push_back(1);
		}
		for(int j=2; j<=19 ; j++)
		{
			scanf("%d",&num);
			for(int i=0 ; i<num ; i++)
			{
				scanf("%d",&v);
				node[j].push_back(v);
				node[v].push_back(j);
			}
		}
		int q_num;
		scanf("%d",&q_num);
		for (int i = 0; i < q_num; ++i)
		{
			int s,d;
			scanf("%d%d",&s,&d);
			int dis=BFS(s,d,node);
			printf("%2d to %2d: %d\n",s,d,dis );
		}printf("\n");
	}
	return 0;
}