#include <iostream>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;
int adjMtx[110][110];
int parent[110];
bool visited[110];
char ans[20];
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
		if(cur>26&&cur<37)ans[cur-27]=parent[cur]+'A'-1; // record parent node
		adjMtx[parent[cur]][cur] -= minWeight;
		adjMtx[cur][parent[cur]] += minWeight;
	}
 
	return minWeight;
}
 
int parseLine(string line)
{
	int job = line[0]-'A'+1;
	int userCnt = line[1]-'0';
	int pcNode;
 
	adjMtx[0][job]=userCnt; // S to job
	//cout<<userCnt<<" "<<job<<" ";
 
	for(int i=3; i<line.size()-1 ;i++)
	{
		pcNode = line[i]-'0';
		adjMtx[job][pcNode+27] +=1 ; // job to pc
		//cout<<pcNode<<" ";
	}//cout<<"\n";
 
	return userCnt;
}
 
int main() {
	int maxFlow;
	int nodeCnt, S, T, edgeCnt, cnt;
 
	string line;
	int t = 0 ;
	while(getline(cin, line))
	{
		memset(adjMtx, 0, sizeof(adjMtx));
		cnt = maxFlow = 0 ;
		S=0;
		T=47; // S(0) -> 1-26 -> 27-36 -> 37-46 -> T(47)
 
		cnt += parseLine(line);
		while(getline(cin, line))
		{
			if (line=="\0")break;		
			cnt += parseLine(line);
		}
 
		for(int i=27; i<37 ;i++)
		{
			adjMtx[i][i+10] +=1 ; // pc capacity is 1
			adjMtx[i+10][T] +=INT_MAX ; // no limit
		}
 
		for(int i=0;i<10;i++)ans[i]='_';
 
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
 
		if(maxFlow<cnt)
			cout<<"!";
		else
		{
			for(int i=0;i<10;i++)cout<<ans[i];
		}cout<<'\n';
 
	}
	return 0;
}
