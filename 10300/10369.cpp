#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

struct disJoint
{
	vector<int> set;

	disJoint(int n)
	{
		for(int i=0 ; i<n ; i++)
			set.push_back(i);
	}

	int find(int x)
	{
		return set[x]==x? x: ( set[x]=find(set[x]) ) ;
	}
	void merge(int x,int y)
	{
		set[find(x)]=find(y);
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
};

struct edge
{	
	int S,D,W;

	edge(int s,int d,int w)
	{
		S=s,D=d,W=w;
	}
	bool operator<(const edge& pos)const
	{
		return this->W<pos.W;
	}
};
vector<edge>edgeList,result;

struct coord
{
	int X,Y;
	coord(int x ,int y)
	{
		X=x,Y=y;
	}	
};

int dis(coord p1,coord p2)
{
	return (p1.X-p2.X)*(p1.X-p2.X)+(p1.Y-p2.Y)*(p1.Y-p2.Y);
}

int Kruskal(int N,int V)
{
	disJoint S(V);
	sort(edgeList.begin(),edgeList.end());

	int len=edgeList.size();
	for(int i=0 ; i<len ; i++)
	{
		if(!S.same(edgeList[i].S,edgeList[i].D))
		{
			result.push_back(edgeList[i]);
			S.merge(edgeList[i].S,edgeList[i].D);
		}
	}
	sort(result.begin(),result.end());

	return result[V-N-1].W;
}

int main()
{
	int T;
	cin>>T;
	for(int t=0 ; t<T ; t++)
	{
		int S,V;
		cin>>S>>V;
		
		vector<coord> graph;
		edgeList.clear();
		result.clear();
		for(int i=0 ; i<V ; i++)
		{
			int x,y;
			cin>>x>>y;
			graph.push_back( coord(x,y) );
		}

		for(int i=0 ; i<V ; i++)
		{
			for(int j=0 ; j<V ; j++)
			{
				edgeList.push_back( edge(i,j,dis( graph[i], graph[j]) ) );
			}
		}
		printf("%.2lf\n",sqrt(Kruskal(S,V)));
	}

	return 0;
}