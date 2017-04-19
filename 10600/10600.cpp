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
	int S,D,W,E;
	edge(int s,int d,int w)
	{
		S=s,D=d,W=w,E=0;
	}
	bool operator<(const edge& pos)const
	{
		return this->W < pos.W;
	}
};

vector<edge> edgeList;
int Kruskal(int c)
{	
	//main algorithm
	sort(edgeList.begin(),edgeList.end());
	int len=edgeList.size();
	disjoint S(c);
	int result=0;
	for(int i=0 ; i<len ; i++)
	{
		if(!S.same(edgeList[i].S,edgeList[i].D) )
		{
			S.merge(edgeList[i].S,edgeList[i].D);
			result+=edgeList[i].W;
			edgeList[i].E=1;
		}
	}
	return result;
}

int secKruskal(int c)
{	
	//main algorithm
	int len=edgeList.size();
	disjoint S(c);
	int result=1e9,tmp,cnt;

	for(int j=0 ; j<len ; j++)
	{
		S.init(c);
		tmp=cnt=0;
		if(edgeList[j].E)
			for(int i=0 ; i<len ; i++)
			{
				if(i!=j)
				{
					if(!S.same(edgeList[i].S,edgeList[i].D) )
					{
						S.merge(edgeList[i].S,edgeList[i].D);
						tmp+=edgeList[i].W;
						cnt++;
					}
				}
			}
		if(cnt==c-1&&tmp<result)result=tmp;
	}
	return result;
}

int main()
{
	int t,c,r;
	cin>>t;
	while(t--)
	{
		cin>>c>>r;

		edgeList.clear();
		for(int i=0 ; i<r ; i++)
		{
			int a,b,w;
			cin>>a>>b>>w;
			edgeList.push_back( edge(a,b,w));
		}
		cout<<Kruskal(c)<<" ";
		cout<<secKruskal(c)<<"\n";
	}

	return 0;
}