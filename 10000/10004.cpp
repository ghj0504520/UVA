#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> point[500];

bool bfs(int n)
{
	int draw[500]={0};
	queue<int> BFS;
	BFS.push(n);
	
	while(!BFS.empty())
	{
		int cur=BFS.front();
		BFS.pop();
		int len=point[cur].size();
		for(int i=0;i<len;i++)
		{
			if(!draw[point[cur][i]])
			{
				BFS.push(point[cur][i]);
				draw[cur]==1?draw[point[cur][i]]=2:draw[point[cur][i]]=1;
			}
			else if(draw[cur]==draw[point[cur][i]])
			{
				return 0;
			}
		}
	}
	return 1;
}

int main()
{
	int num;
	while(cin>>num,num)
	{
		int edge;
		cin>>edge;
		for(int i=0;i<500;i++)
			point[i].clear();
		int start,dest;
		for(int i=0;i<edge;i++)
		{
			cin>>start>>dest;
			point[start].push_back(dest);
			point[dest].push_back(start);
		}
		if(bfs(start))
			cout<<"BICOLORABLE.\n";
		else
			cout<<"NOT BICOLORABLE.\n";
	}
	return 0;
}
