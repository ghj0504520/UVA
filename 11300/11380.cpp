#include <iostream>
#include <queue>
#include <climits>
#include <string.h>
using namespace std;
 
int adjMtx[2048][2048];
int parent[2048];
bool visited[2048];
int direction[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1} };
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
	int nodeCnt, S, T, X, Y, P;
	int u, v;
	char c;
 
	while(cin >> Y >> X >> P)
	{
		memset(adjMtx, 0, sizeof(adjMtx));
		S = maxFlow = 0 ;
 
		nodeCnt = X*Y;
		T = nodeCnt*2+1;
		for(int j=0 ; j<Y ; j++)
		{
			for(int i=0 ; i<X ; i++)
			{
				u = X * j + i + 1;
				cin >> c;    // splitted each node by its pixel value
				if (c == '.') adjMtx[u][u + nodeCnt] = 1;            // move capacity is 1
				else if (c == '@') adjMtx[u][u + nodeCnt] = INT_MAX; // move capacity is inifinity
				else if (c == '*')				     // move capacity is 1 and with 1 in it from S
				{
					adjMtx[u][u + nodeCnt] = 1;
					adjMtx[S][u] = 1;
				}
				else if (c == '#')				    // move capacity is inifinity and with P in it to T
				{
					adjMtx[u][u + nodeCnt] = INT_MAX;
					adjMtx[u + nodeCnt][T] = P;
				}
 
				for (int k = 0; k < 4; ++k)
				{
					int x = i + direction[k][0];
					int y = j + direction[k][1];
					if (x >= 0 && y >= 0 && x < X && y < Y)
					{
						v = X * y + x + 1;
						adjMtx[u + nodeCnt][v] = INT_MAX; // egress from splitted node
					}
				}
 
			}
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
