#include <iostream>
#include <vector>
using namespace std;

vector<int> node[110], ans;
int vis[110];

void dfs(int n)
{
	vis[n] =1;
	int l = node[n].size();
	for(int i=0 ; i<l ; i++)
	{
		if (!vis [ node[n][i] ])
			dfs(node[n][i]);
	}

	// topological sort record dfs finish vertex
	ans.push_back(n);
	return;
}

int main(int argc, char const *argv[])
{
	int n, m;
	while(cin>>n>>m)
	{
		if(!n&&!m)break;

		ans.clear();
		for(int i=0 ; i<110 ; i++)
		{
			node[i].clear();
			vis[i] = 0;
		}

		int s,v;
		while(m--)
		{
			cin>>s>>v;
			node[s].push_back(v);
		}

		for(int i=1 ; i<=n ; i++)
			if(!vis[i])
				dfs(i);

		// reverse the dfs finish vertex
		for(int i=n-1 ; i>=0 ; i--)
			cout<<ans[i]<<(i!=0? " ":"\n");
	}
	return 0;
}