#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

map<string,vector<string> >HASH;
map<string,string >vis;

void backtrack(string cur)
{
	if(cur!="***")
	{
		backtrack(vis[cur]);
		if(vis[cur]!="***")cout<<vis[cur]<<" "<<cur<<"\n";
	}
}

bool BFS(string S,string D)
{
	queue<string>bfs;
	bfs.push(S);
	vis.insert(std::pair<string,string >(S,"***"));

	while(bfs.size())
	{
		string cur=bfs.front();
		bfs.pop();

		if(cur==D)
		{
			backtrack(cur);
			return 1;
		}

		int len=HASH[cur].size();
		for(int i=0 ; i<len ; i++)
		{
			string next=HASH[cur][i];
			if(!vis.count(next))
			{
				vis.insert(std::pair<string,string >(next,cur));
				bfs.push(next);
			}
		}
	}return 0;
}

int main()
{
	int T,t=0;
	while(cin>>T)
	{
		HASH.clear();
		vis.clear();
		if(t++)cout<<"\n";
		for(int i=0 ; i<T ; i++)
		{
			string a,b;
			cin>>a>>b;
			HASH[a].push_back(b);
			HASH[b].push_back(a);
		}
		string start,dest;
		cin>>start>>dest;
		bool check=BFS(start,dest);
		if(!check)cout<<"No route\n";
	}
	return 0;
}