#include <iostream>
#include <queue>
#include <climits>
#include <string.h>
using namespace std;
 
int adjMtx[200][200];
int parent[200];
bool visited[200];
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
 
	while(cin >> nodeCnt >> edgeCnt)
	{
		if(!nodeCnt && !edgeCnt) break;
 
		memset(adjMtx, 0, sizeof(adjMtx));
		maxFlow = 0 ;
 
		int internalCnt = nodeCnt-2;
		S = 1;
		T = nodeCnt+internalCnt;
 
		for(int i=0 ; i<internalCnt ; i++) // split internal node capacity; nodeU (C) into nodeU1 -> edge (C) -> nodeU2
		{
			cin >> u >> c;
			adjMtx[u][u+internalCnt] = adjMtx[u+internalCnt][u] = c;
		}
 
		for(int i=0 ; i<edgeCnt ; i++) // egress flow always from splitted node
		{
			cin >> u >> v >> c;
			int splitU, splitV;
			if (u == nodeCnt) u = T;
			if (v == nodeCnt) v = T;
			splitU = (u != 1 && u != T ? u + internalCnt : u);
			splitV = (v != 1 && v != T ? v + internalCnt : v);
			adjMtx[splitU][v] = adjMtx[splitV][u] = c;
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
