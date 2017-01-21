#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct disjoint
{
	vector<int > set;

	disjoint(int n)
	{
		for(int i=0 ; i<n ; i++)
			set.push_back(i);
	}

	int find(int x)
	{
		return set[x]==x? x: ( set[x]=find(set[x]) );
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
		return this->W < pos.W;
	}
};

vector<edge>edgeList;

int Kruskal(int V,int E)
{
	sort(edgeList.begin(),edgeList.end());
	int result=0;
	disjoint S(V);

	for(int i=0 ; i<E ; i++)
	{
		if(!S.same(edgeList[i].S,edgeList[i].D))
		{
			result+=edgeList[i].W;
			S.merge(edgeList[i].S,edgeList[i].D);
		}
	}
	return result;
}

int main()
{
	int V,E,S,D,W,total;
	while(cin>>V>>E)
	{
		if(!V&&!E)break;
		edgeList.clear();
		total=0;
		for(int i=0 ; i<E ; i++)
		{
			cin>>S>>D>>W;
			total+=W;
			edgeList.push_back( edge(S,D,W) );
		}
		cout<<total-Kruskal(V,E)<<"\n";
	}
	return 0;
}