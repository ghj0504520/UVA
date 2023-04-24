#include <iostream>
#include <queue>
#include <climits>
#include <string.h>
using namespace std;
 
int adjMtx[110][110];
int parent[110];
bool visited[110];
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
	int t = 0, maxFlow;
	int nodeCnt, S, T, edgeCnt;
	int u, v, c;
 
	while((cin >> nodeCnt) && nodeCnt)
	{
		memset(adjMtx, 0, sizeof(adjMtx));
		maxFlow = 0 ;
 
		cin >> S >> T >> edgeCnt;
 
		for (int i = 0; i < edgeCnt; i++)
		{
			cin >> u >> v >> c;
			adjMtx[u][v] += c; // might multiple edge
			adjMtx[v][u] += c;
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
				for(int next=1 ; next <= nodeCnt ; next++)
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
 
		cout<< "Network "<< ++t;
		cout<< "\nThe bandwidth is "<< maxFlow<< ".\n\n";
 
	}
	return 0;
}
