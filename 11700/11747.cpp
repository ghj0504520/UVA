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
vector<edge>edgeList,remain;

bool Kruskal(int V,int E)
{
	disJoint S(V);
	remain.clear();

	for(int i=0 ; i<E ; i++)
	{
		if(!S.same(edgeList[i].S,edgeList[i].D))
		{
			S.merge(edgeList[i].S,edgeList[i].D);
		}
		else
		{
			remain.push_back(edgeList[i]);
		}
	}

	int len=remain.size();

	if(!len)return 0;

	sort(remain.begin(),remain.end());
	for(int i=0 ; i<len ; i++)
	{	
		if(i)cout<<" ";
		cout<<remain[i].W;
	}cout<<"\n";

	return 1;
}

int main()
{
	int V,E;
	while(cin>>V>>E)
	{
		if(!V&&!E)break;

		edgeList.clear();

		for(int i=0 ; i<E ; i++)
		{
			int s,d,w;
			cin>>s>>d>>w;
			edgeList.push_back( edge(s,d,w) );
		}

		if(!Kruskal(V,E))
		{
			cout<<"forest\n";
		}
	}
	return 0;
}