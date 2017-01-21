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

int Kruskal(int V,int E)
{
	disJoint S(V);
	sort(edgeList.begin(),edgeList.end());

	int result=0,cnt=0;
	for(int i=0 ; i<E ; i++)
	{
		if(!S.same(edgeList[i].S,edgeList[i].D))
		{
			result+=edgeList[i].W;
			S.merge(edgeList[i].S,edgeList[i].D);
			cnt++;
		}
	}

	return cnt==(V-1)? result:-1;
}

int main()
{
	int V,E;
	while(cin>>V>>E)
	{
		if(!V&&!E)break;

		edgeList.clear();
		map<string,int>table;
		int cnt=0;

		for(int i=0 ; i<V ; i++)
		{
			string v;
			cin>>v;
			table[v]=cnt++;
		}

		for(int i=0 ; i<E ; i++)
		{
			string s,d;
			int w;
			cin>>s>>d>>w;
			edgeList.push_back( edge(table[s],table[d],w) );
		}
		
		string s;
		cin>>s;
		int ans=Kruskal(V,E);
		if(ans!=-1)
		{
			cout<<ans<<"\n";
		}
		else
		{
			cout<<"Impossible\n";
		}
	}
	return 0;
}