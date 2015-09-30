#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;
int N,S;
struct edge
{
	int s,d,w;
	edge(int S,int D,int W)
	{
		s=S,d=D,w=W;
	}
};
vector<edge> Graph;

void Bellman(int D[],int SRC)
{
	for(int i=0 ; i<=N ; i++)
	{
		D[i]=INF;
	}D[SRC]=0;

	int len=Graph.size();
	for(int i=0 ; i<N-1 ; i++)
	{
		for(int j=0 ; j<len ; j++)
		{
			int s,d,w;
			s=Graph[j].s;
			d=Graph[j].d;
			w=Graph[j].w;

			D[d]=min(D[d],D[s]+w);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	int T=0;
	while(cin>>N,N)
	{
		int Dst[N+1];
		cin>>S;
		int s,d;
		Graph.clear();
		while(cin>>s>>d)
		{
			if(!s&&!d)break;
			Graph.push_back(edge(s,d,-1));
		}
		Bellman(Dst,S);
		int Max=INF,Mindex;
		for(int i=1 ; i<=N ; i++)
		{
			if(Max > Dst[i])
			{
				Max=Dst[i];
				Mindex=i;
			}
		}
		cout<<"Case "<<++T<<": The longest path from ";
		cout<<S<<" has length "<<-Max<<", finishing at "<<Mindex<<".\n\n";
	}
	return 0;
}