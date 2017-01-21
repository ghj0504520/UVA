#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

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
vector<edge>edgeList;

int main()
{
	int V,t=0;
	while(cin>>V)
	{
		if(t++)cout<<"\n";
		edgeList.clear();
		int oldCost=0;
		for(int i=0 ; i<V-1 ; i++)
		{
			int s,d,w;
			cin>>s>>d>>w;
			oldCost+=w;
		}

		int newLine,oldLine;
		cin>>newLine;
		for(int i=0 ; i<newLine ; i++)
		{
			int s,d,w;
			cin>>s>>d>>w;
			edgeList.push_back( edge(s-1,d-1,w) );
		}
		cin>>oldLine;
		for(int i=0 ; i<oldLine ; i++)
		{
			int s,d,w;
			cin>>s>>d>>w;
			edgeList.push_back( edge(s-1,d-1,w) );
		}

		int len=edgeList.size(),newCost=0;
		disJoint S(V);
		sort(edgeList.begin(),edgeList.end());

		for(int i=0 ; i<len ; i++)
		{
			if(!S.same(edgeList[i].S,edgeList[i].D))
			{
				newCost+=edgeList[i].W;
				S.merge(edgeList[i].S,edgeList[i].D);
			}
		}cout<<oldCost<<"\n"<<newCost<<"\n";
	}
	return 0;
}