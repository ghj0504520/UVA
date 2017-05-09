#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

struct disjoint
{
	vector<int > set;
	int count[2*100000+10];

	disjoint(int n)
	{
		for(int i=0 ; i<=n ; i++)
		{
			set.push_back(i);
			count[i]=1;
		}
	}

	int find(int x)
	{
		return set[x]==x? x: ( set[x]=find(set[x]) );
	}
	void merge(int x,int y)
	{
		int rootX=find(x),rootY=find(y);/*figure out*/
		if(!same(rootX,rootY))
		{
			set[rootX]=rootY;
			count[rootY]+=count[rootX];
		}
		cout<<count[rootY]<<'\n';
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
};

int main()
{
	int T;
	cin>>T;
	for(int t=0 ; t<T ; t++)
	{
		int n,idx=0;
		cin>>n;
		string a,b;
		disjoint SET(min(2*n,100000));
		map<string,int>hash;
		for(int i=0 ; i<n ; i++)
		{
			cin>>a>>b;
			if(!hash[a])hash[a]=++idx;
			if(!hash[b])hash[b]=++idx;

			SET.merge(hash[a],hash[b]);
		}
	}
	return 0;
}
