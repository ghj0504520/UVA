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
		for(int i=0 ; i<=n ; i++)
			set.push_back(i);
	}
	void init(int n)
	{
		set.clear();
		for(int i=0 ; i<=n ; i++)
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
int Kruskal(int c,int s,int d)
{	
	//main algorithm
	sort(edgeList.begin(),edgeList.end());
	int len=edgeList.size();
	disjoint S(c);
	
	for(int i=0 ; i<len ; i++)
	{
		if(!S.same(edgeList[i].S,edgeList[i].D) )
		{
			S.merge(edgeList[i].S,edgeList[i].D);
			if(S.same(s,d))
			{
				return edgeList[i].W;
			}
		}
	}
}

int main()
{
	int c,r,t=0;
	while(cin>>c>>r)
	{
		if(!c&&!r)break;

		edgeList.clear();
		for(int i=0 ; i<r ; i++)
		{
			int a,b,w;
			cin>>a>>b>>w;
			edgeList.push_back( edge(a,b,w));
		}
		int s,d,p;
		cin>>s>>d>>p;
		int ans=Kruskal(c,s,d);
		ans=(p%(ans-1)==0)?(p/(ans-1)):(p/(ans-1)+1);  
		
		cout<<"Scenario #"<< ++t <<"\n";  
		
		cout<<"Minimum Number of Trips = "<<ans<<"\n\n";  
	}

	return 0;
}