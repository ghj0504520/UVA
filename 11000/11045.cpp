#include <iostream>
#include <queue>
#include <climits>
#include <string.h>
using namespace std;
 
int adjMtx[50][50];
int parent[50];
bool visited[50];
 
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
 
int sizeMap(string s)
{
	if (s=="XXL")
		return 1;
	else if(s=="XL")
		return 2;
	else if(s=="L")
		return 3;
	else if(s=="M")
		return 4;
	else if(s=="S")
		return 5;
	else if(s=="XS")
		return 6;
	return -1;
}
 
int main() {
 
	int maxFlow;
	int nodeCnt, S, T, edgeCnt;
 
	int t;
	cin>>t;
	while(t--)
	{
		maxFlow = 0;
		memset(adjMtx, 0, sizeof(adjMtx));
 
		int n, m;
		cin>>n >>m;
		S = 0;
		T = 37; // S(0) -> 1-6 -> 1-30 -> T(37)
 
		for(int i=0; i<6; i++)
		{
			adjMtx[S][i+1] = n/6; // each size has N/6 number from S
		}
		for(int i=0; i<m; i++)
		{
			string a,b;
			cin >>a >>b;
			adjMtx[sizeMap(a)][i+1+6] = 1; // size A to people
			adjMtx[sizeMap(b)][i+1+6] = 1; // size B to people
			adjMtx[i+1+6][T] =1; //people to T
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
				for(int next=S ; next <= T ; next++)
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
		cout<<(maxFlow == m? "YES\n":"NO\n");
	}
	return 0;
}

