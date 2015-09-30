#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

#define INF 1e9

using namespace std;
int N,M,S,D,cntSize;
int inQueue[20000+10],Distance[20000+10];

struct edge
{
	int s,d,w;
	edge(int S,int D,int W)
	{
		s=S,d=D,w=W;
	}
};
vector<edge> Graph[20000+10];

bool SPFA(int Src)
{
	memset(inQueue,0,sizeof(inQueue));
	memset(Distance,0,sizeof(Distance));
	int negativeCatch[20000+10];
	memset(negativeCatch,0,sizeof(negativeCatch));

	for(int i=0 ; i<N ; i++)Distance[i]=INF;
	Distance[Src]=0;
	inQueue[Src]=1;

	queue<int>spfa;
	spfa.push(Src);

	while(!spfa.empty())
	{
		int cur=spfa.front();
		spfa.pop();

		inQueue[cur]=0;

		cntSize=Graph[cur].size();
		for(int i=0 ; i<cntSize ; i++)
		{
			int s=Graph[cur][i].s,d=Graph[cur][i].d,w=Graph[cur][i].w;
			if(cur==s && Distance[d] > Distance[s]+w)
			{
				Distance[d] = Distance[s]+w;
				if(!inQueue[d])
				{
					spfa.push(d);
					inQueue[d]=1;
					negativeCatch[d]++;
				}
				if(negativeCatch[d]>=N)return 0;
			}
		}
	}

	return 1;
}

int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	for(int i=0 ; i<T ; i++)
	{
		cin>>N>>M>>S>>D;
		for (int i = 0; i < 20000+10; ++i)
		{
			Graph[i].clear();
		}
		
		for(int i=0 ; i<M ; i++)
		{
			int s,d,w;
			cin>>s>>d>>w;
			Graph[s].push_back(edge(s,d,w));
			Graph[d].push_back(edge(d,s,w));
		}
		SPFA(S);
		cout<<"Case #"<<i+1<<": ";
		Distance[D]==INF? cout<<"unreachable\n":cout<<Distance[D]<<"\n";
	}
	return 0;
}