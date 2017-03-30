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
		return this->W > pos.W;
	}
};

vector<edge> edgeList;

int Kruskal(int c)
{	
	//main algorithm
	sort(edgeList.begin(),edgeList.end());
	int len=edgeList.size();
	disjoint S(c);
	int min=10000;
	for(int i=0 ; i<len ; i++)
	{
		if(!S.same(edgeList[i].S,edgeList[i].D) )
		{
			S.merge(edgeList[i].S,edgeList[i].D);
			
			if(edgeList[i].W<min)min=edgeList[i].W;
		}
	}
	return min;
}

int main()
{
	int T;
	cin>>T;
	for(int t=0 ; t<T ; t++)
	{
		cout<<"Case #"<<t+1<<": ";
		int c,r;
		cin>>c>>r;
		edgeList.clear();
		for(int i=0 ; i<r ; i++)
		{
			int a,b,w;
			cin>>a>>b>>w;
			edgeList.push_back( edge(a,b,w));
		}cout<<Kruskal(c)<<"\n";
	}

	return 0;
}