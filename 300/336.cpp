#include <iostream>
#include <map>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int BFS(int S,int TTL,map<int,int>HASH,vector<int>NODE[])
{
	int step=0,num_reach=0;
	queue<int>bfs;
	map<int ,int >check;
	bfs.push(HASH[S]);
	check.insert(std::pair<int,int>(HASH[S],step));
	num_reach=1;
	while(!bfs.empty())
	{
		int cur=bfs.front();
		bfs.pop();
		step=check[cur];
		if(step>=TTL)	break;
		for(int i=0 ; i<NODE[cur].size() ; i++)
		{
			int now=NODE[cur][i];
			if(check.find(now)==check.end())
			{
				bfs.push(now);
				check.insert(std::pair<int,int>(now,step+1));
				num_reach++;
			}
		}
	}
	return num_reach;
}

int main(int argc, char const *argv[])
{
	int num,t=0;
	while(scanf("%d",&num)!=EOF)
	{
		if(!num)break;
		map<int,int>node_hash;
		vector<int>node[200];
		int node_num=0,n1,n2;
		for (int i = 0; i < num; ++i)
		{
			scanf("%d%d",&n1,&n2);
			if(node_hash.find(n1)==node_hash.end())
				node_hash.insert(std::pair<int,int>(n1,++node_num));
			if(node_hash.find(n2)==node_hash.end())
				node_hash.insert(std::pair<int,int>(n2,++node_num));
			node[ node_hash[n1] ].push_back(node_hash[n2]);
			node[ node_hash[n2] ].push_back(node_hash[n1]);
		}
		int start,ttl;
		while(scanf("%d%d",&start,&ttl)!=EOF)
		{
			if(!start&&!ttl)break;
			int R=BFS(start,ttl,node_hash,node);
			cout<<"Case "<<++t<<": "<<node_num-R<<" nodes not reachable from node "<<start<<" with TTL = "<<ttl<<".\n";
		}
		getchar();
	}
	return 0;
}