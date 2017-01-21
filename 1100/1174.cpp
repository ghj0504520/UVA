#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string,int>Table;

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
		if(!S.same(edgeList[i].S-1,edgeList[i].D-1))
		{
			result+=edgeList[i].W;
			S.merge(edgeList[i].S-1,edgeList[i].D-1);
		}
	}
	return result;
}

int main()
{
	int T;
	cin>>T;

	for(int i=0 ; i<T ; i++)
	{
		if(i)cout<<"\n";
		Table.clear();
		edgeList.clear();
		int cnt=1;

		int V,E;
		cin>>V>>E;

		for(int j=0 ; j<E ; j++)
		{
			string s,d;
			int w;
			cin>>s>>d>>w;
			if(!Table[s])Table[s]=cnt++;
			if(!Table[d])Table[d]=cnt++;

			edgeList.push_back( edge(Table[s],Table[d],w) );

		}
		cout<<Kruskal(V,E)<<"\n";
	}

	return 0;
}