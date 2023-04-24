#include <iostream>
#include <queue>
#include <climits>
#include <string.h>
using namespace std;
 
int adjMtx[300][300];
int parent[300];
bool visited[300];
int updateFlow1(int s, int u, int v, int minWeight) // recursive update
{
	if(v == s) return minWeight;
	minWeight = updateFlow1(s, parent[u], u, min( adjMtx[u][v], minWeight));
	adjMtx[u][v] -= minWeight;
	adjMtx[v][u] += minWeight;
 
	return minWeight;
}
 
int updateFlow2(int s, int t) // iterative update
{
	int cur=t, minWeight = INT_MAX;
	while(cur!=s)
	{
		minWeight = min( adjMtx[parent[cur]][cur], minWeight);
		cur= parent[cur];
	}
 
	for(int cur=t ; cur!=s ; cur=parent[cur])
	{
		adjMtx[parent[cur]][cur] -= minWeight;
		adjMtx[cur][parent[cur]] += minWeight;
	}
 
	return minWeight;
}
 
 
int main() {
	int maxFlow;
	int nodeCnt, S, T, edgeCnt;
	int u, v, c;
 
	while(cin >> nodeCnt)
	{
		memset(adjMtx, 0, sizeof(adjMtx));
		S = maxFlow = 0 ;
		T = nodeCnt*2 +1;
 
		for (int n = 1; n <= nodeCnt; n++) // split node capacity; nodeU (C) into nodeU1 -> edge (C) -> nodeU2
		{
			cin >> adjMtx[n][n+nodeCnt] ;
		}
 
		cin >> edgeCnt;
 
		for (int e = 0; e < edgeCnt; e++) // egress flow always from splitted node
		{
			cin >> u >> v >> c;
			adjMtx[u+nodeCnt][v] = c;
		}
 
		int b,d,p;
		cin>>b>>d;
		while(b--) // node connect with S, ingress into original node
		{
			cin>>p;
			adjMtx[S][p] = INT_MAX;
		}
		while(d--) // node connect with T, egress from splitted node
		{
			cin>>p;
			adjMtx[p+nodeCnt][T] = INT_MAX;
		}
 
 
		// Edmonds–Karp Algorithm
		while(1)
		{
			queue<int> BFS;
			memset(parent, 0, sizeof(parent));
			memset(visited, 0, sizeof(visited));
			BFS.push(S);
			visited[S] = 1;
 
			while(!BFS.empty() && !visited[T])
			{
				int cur = BFS.front();
				BFS.pop();
				for(int next=0 ; next <= T ; next++)
				{
					if(!visited[next] && adjMtx[cur][next]>0)
					{
						BFS.push(next);
						visited[next] = 1;
						parent[next] = cur;
 
					}
				}
			}
			if (!visited[T]) break;
 
			//maxFlow += updateFlow1(S,parent[T],T,INT_MAX);
			maxFlow += updateFlow2(S,T);
		}
 
		cout<< maxFlow<< "\n";
 
	}
	return 0;
}
