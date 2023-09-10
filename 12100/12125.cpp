#include <iostream>
#include <cstring>
#include <climits>
#include <queue>
#include <map>
#include <vector>
using namespace std;

vector< vector<int> > adjMtx,orginal; // for reusing original graph
int parent[220];
bool visited[220];

int updateFlowRe(int s, int u, int v, int bottleNeck) // recursive update flow
{
	if(v == s) return bottleNeck;
	bottleNeck = updateFlowRe(s,parent[u],u,min( adjMtx[u][v], bottleNeck));
	adjMtx[u][v] -= bottleNeck;
	adjMtx[v][u] += bottleNeck;

	return bottleNeck;	
}

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

struct coord
{
	double X,Y;
	coord(int x,int y)
	{
		X=(double)x;
		Y=(double)y;
	}
	bool jump(const coord &a,double maxJ)
	{
		return (maxJ * maxJ > (this->X - a.X)*(this->X - a.X) + (this->Y - a.Y)*(this->Y - a.Y))?1:0;
	}
};

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;

	int S,T,maxFlow;
	while(t--)
	{
		S=0;

		orginal.assign(250, vector<int>(250, 0));
		std::vector<coord> ice;

		int num;
		cin>>num;
		double dis;
		cin>>dis;

		T=2*num+1;
		int sumP=0;

		int x,y;
		int numP,numJ;

		//S(0)-> 1-ices-> 1-internal-ices (-> other ices within jump distance)
		//             -> T
		for(int i=1 ; i<=num ; i++)
		{
			cin>>x>>y>>numP>>numJ;
			sumP+=numP;
			orginal[S][i]=numP;       // from S to ice with number of penguins
			orginal[i][i+num]=numJ;   // from ice to internal-ice with capacity of ice
			ice.push_back(coord(x,y));
		}
		for(int i=1 ; i<=num ; i++)
			for(int j=1 ; j<=num ; j++)
				if(i!=j&&ice[i-1].jump(ice[j-1],dis))
					orginal[i+num][j]=INT_MAX; // from ice to other ices within jump distance


		std::vector<int> ans;
		for(int i=1 ; i<=num ; i++) // each run try an target ice
		{
			adjMtx = orginal; 		// duplicate the graph
			adjMtx[i][T]=INT_MAX; // from ice to finish state,
								  // no need to consider capacity ~ from i instead of i+num

			maxFlow=0;
			
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
					for(int next=S ; next<=T ; next++)
					{
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

			// max flow match sum of penguins imply all penguins can meet on this ice
			if (maxFlow == sumP) ans.push_back(i - 1);
		}


		if (!ans.empty())
		{
			int len = ans.size();
			for (int i = 0; i < len; ++i)
			{
				if(i)cout<<" ";
				cout<<ans[i];
			}
			cout<<"\n";
		}
		else cout<<"-1\n";
	}
	
	return 0;
}