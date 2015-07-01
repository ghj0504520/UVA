#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

void DFS(int cur,vector<char> node[],bool visit[])
{
	visit[cur]=1;
	int len=node[cur].size();
	for(int i=0 ; i<len ; i++)
	{
		if(!visit[node[cur][i]-'A'])
		{
			DFS(node[cur][i]-'A',node,visit);
		}
	}
}

int main()
{
	int num;
	cin>>num;
	for(int i=0 ; i<num ; i++)
	{
		if(i)cout<<'\n';
		int max_node;
		char Max;
		cin>>Max;
		getchar();
		max_node=Max-'A'+1;
		vector<char> node[30];
		char road[5],start,dest;
		while(1)
		{
			cin.getline(road,4);
			if(road[0]=='\0')break;
			sscanf(road,"%c%c",&start,&dest);
			//cout<<start<<" "<<dest<<'\n';
			node[start-'A'].push_back(dest);
			node[dest-'A'].push_back(start);
		}
		int count=0;
		bool visit[30];
		memset(visit,0,sizeof(visit));
		for(int i=0 ; i<max_node ; i++)
		{
			if(!visit[i])
			{
				DFS(i,node,visit);
				count++;
			}
		}
		cout<<count<<'\n';
	}
	return 0;
}
