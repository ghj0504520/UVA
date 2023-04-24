#include <iostream>
#include <queue>
#include <climits>
#include <string.h>
using namespace std;
 
int adjMtx[600][600];
int parent[600];
bool visited[600];
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
	int t, maxFlow;
	int S, T, p, s, c, m;
	int u, v;
 
	cin >> t;
	while(t--)
	{
 
		memset(adjMtx, 0, sizeof(adjMtx));
		maxFlow = 0 ;
 
		cin>>p >>s >>c >>m;
 
		S = 0;
		T = p+s+1;
		while(m--) //teams to sites
		{
			cin>>u >>v;
			adjMtx[u][v+p] = 1;
		}
 
		for (int i = 1; i <= p; ++i) adjMtx[S][i] = 1; // S to teams
		for (int i = p + 1; i <= p + s; ++i) adjMtx[i][T] = c; // sites to T
 
 
 
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
 
			maxFlow += updateFlow1(S,parent[T],T,INT_MAX);
			//maxFlow += updateFlow2(S,T);
		}
 
		cout<< maxFlow<< "\n";
 
	}
	return 0;
}
