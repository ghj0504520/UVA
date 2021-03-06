#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>

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

vector<edge> edgeList;
int result=0;
int Kruskal(int c)
{	
	//main algorithm
	sort(edgeList.begin(),edgeList.end());
	int len=edgeList.size();
	disjoint S(c);
	int max=-1;
	for(int i=0 ; i<len ; i++)
	{
		if(!S.same(edgeList[i].S,edgeList[i].D) )
		{
			S.merge(edgeList[i].S,edgeList[i].D);
			result++;
			if(edgeList[i].W>max)max=edgeList[i].W;
		}
	}
	return max;
}

int main()
{
	int c,r;
	while(cin>>c>>r)
	{
		if(!c&&!r)break;

		result=0;
		edgeList.clear();
		for(int i=0 ; i<r ; i++)
		{
			int a,b,w;
			cin>>a>>b>>w;
			edgeList.push_back( edge(a,b,w));
		}
		int ans=Kruskal(c);
		if(result==c-1)cout<<ans<<"\n";
		else cout<<"IMPOSSIBLE\n";
	}

	return 0;
}