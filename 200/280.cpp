#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> node[110];
int vis[110];
int ans;

void dfs(int v)
{
	int l = node[v].size();
	for(int i=0 ; i<l ; i++)
	{
		if (!vis [ node[v][i] ])
		{
			vis[ node[v][i] ] =1;
			ans++; 
			dfs(node[v][i]);
		}
	}
	return;
}

int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n)
	{
		if(!n)break;

		for(int i=0 ; i<110 ; i++)
			node[i].clear();

		int v1, v2;
		while(cin>>v1)
		{
			if(!v1)break;
			while(cin>>v2)
			{
				if(!v2)break;
				node[v1].push_back(v2);
			}
		}

		int qn, q;
		cin>>qn;
		while(qn--)
		{
			cin>>q;
			
			ans=0;
			memset(vis,0,sizeof(vis));

			dfs(q);

			cout<<n-ans;
			for(int i=1 ; i<=n ; i++)
			{
				if(vis[i]==0)
					cout<<" "<<i;
			}cout<<'\n';
		}
	}
	return 0;
}