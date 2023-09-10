#include <iostream>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
using namespace std;

int adjMtx[1050][1050];
int parent[1050];
bool visited[1050];
vector<int> adjList[1050];

int updateFlowIt(int s,int t) // iterative update flow
{
	int cur=t, bottleNeck = INT_MAX;
	while(cur!=s)
	{
		bottleNeck = min(adjMtx[parent[cur]][cur],bottleNeck);
		cur = parent[cur];
	}
	for(int cur=t; cur!=s; cur=parent[cur])
	{
		adjMtx[parent[cur]][cur] -= bottleNeck;
		adjMtx[cur][parent[cur]] += bottleNeck;
	}
	return bottleNeck;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);

	int k,p;
	int S,T,maxFlow;
	while(cin>>k>>p)
	{
		if(!k&&!p)break;

		S=0;
		T=k+p+1;
		maxFlow=0;
		int sumProb = 0;
		memset(adjMtx,0,sizeof(adjMtx));

		for(int i=0 ; i<1050 ; i++)  // adj list when graph is sparce
			adjList[i].clear();

		//S(0)-> 1-problems-> 1-categories-> T
		for(int i=1 ; i<=k ; i++)
		{
			int num;
			cin>>num;
			adjMtx[i][T]=num;        // from category to T with number of problem each category
			adjList[i].push_back(T); // bidirectional edge
			adjList[T].push_back(i);
			sumProb+=num;
		}

		for(int i=0 ; i<p ; i++)
		{
			adjMtx[S][k+1+i]=1;		// from S to problem with 1
			adjList[S].push_back(k+1+i); // bidirectional edge
			adjList[k+1+i].push_back(S);
			int numProb,probCat;
			cin>>numProb;

			for(int j=0 ; j<numProb ; j++)
			{
				cin>>probCat;
				adjMtx[k+1+i][probCat] =1;		// from each problem to category with 1
				adjList[k+1+i].push_back(probCat); // bidirectional edge
				adjList[probCat].push_back(k+1+i);
			}
		}

		// Edmonds–Karp Algorithm
		while(1)
		{
			queue<int> BFS;
			memset(parent,0, sizeof(parent));
			memset(visited,0, sizeof(visited));
			BFS.push(S);
			visited[S]=1;

			while(!BFS.empty()&&!visited[T])
			{
				int cur = BFS.front();
				BFS.pop();
				int len = adjList[cur].size();
				for(int i=0 ; i<len ; i++)
				{
					int next = adjList[cur][i];
					if(!visited[next]&&adjMtx[cur][next]>0)
					{
						BFS.push(next);
						visited[next]=1;
						parent[next] =cur;
					}
				}
			}

			if(!visited[T])break;
			maxFlow+= updateFlowIt(S,T);
		}

		// max flow match sum of problem demand
		if(sumProb!=maxFlow)
			cout<<"0\n";
		else
		{
			cout<<"1\n";
			for(int i=1 ; i<=k ; i++)
			{
				bool flag=0;
				int len = adjList[i].size();
				for(int j=0 ; j<len ; j++)
					if(adjList[i][j]<T&&adjMtx[i][adjList[i][j]]==1) // reverse is one imply from problem to category is exhaust,
					{                                                // problem is selected by category
						if(flag)
							cout<<' ';
						else flag=1;
						cout<<adjList[i][j]-k;
					}
				cout<<"\n";
			}
		}
	}

	return 0;
}