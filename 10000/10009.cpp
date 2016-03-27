#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>

using namespace std;

map<string,vector<string> > ROAD,ANS;
map<string,string> vis;

void backtrack(string cur)
{
	if(cur=="*****")return ;

	else
	{
		backtrack(vis[cur]);
		cout<<cur[0];
	}
}

void BFS(string S,string D)
{
	queue<string>bfs;
	bfs.push(S);
	vis[S]="*****";

	while(!bfs.empty())
	{
		string cur=bfs.front();
		bfs.pop();

		if(cur==D)
		{
			backtrack(cur);
			cout<<"\n";
		}
		else
		{
			int len=ROAD[cur].size();

			for(int i=0 ; i<len ; i++)
			{
				string next=ROAD[cur][i];
				if(!vis.count(next))
				{
					vis[next]=cur;
					bfs.push(next);
				}
			}
		}
	}
}

int main()
{
	int T;
	cin>>T;
	for(int t=0 ; t<T ; t++)
	{
		if(t)cout<<"\n";
		ROAD.clear();
		int p,q;
		cin>>p>>q;

		for(int i=0 ; i<p ; i++)
		{
			string a,b;
			cin>>a>>b;
			ROAD[a].push_back(b);
			ROAD[b].push_back(a);
		}
		string start,dest;
		for(int i=0 ; i<q ; i++)
		{
			vis.clear();
			cin>>start>>dest;
			BFS(start,dest);
		}
	}
	return 0;
}