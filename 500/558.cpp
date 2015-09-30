#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f

using namespace std;
struct side
{
	int s,d,w;
}Graph[2100];
int n,m;

bool Bellman(int S)
{
	int D[n];
	for (int i = 0; i < n; ++i)	D[i]=INF;
	D[S]=0;

	for (int i = 0; i < n-1 ; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int s,d,w;
			s=Graph[j].s ,d=Graph[j].d , w=Graph[j].w;
			D[d]=min(D[d],D[s]+w);
		}
	}
	for (int j = 0; j < m; ++j)
	{
		int s,d,w;
		s=Graph[j].s ,d=Graph[j].d , w=Graph[j].w;
		if(D[d] > D[s]+w)return 0;
	}
	return 1;
}

int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=0 ; i<m ; i++)
		{
			int s,d,w;
			cin>>s>>d>>w;
			Graph[i].s=s ,Graph[i].d=d ,Graph[i].w=w;
		}
		int check=Bellman(0);
		check?cout<<"not possible\n":cout<<"possible\n";
	}
	return 0;
}