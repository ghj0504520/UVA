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

	disjoint(int n)
	{
		for(int i=0 ; i<=n ; i++)
		{
			set.push_back(i);
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
		}
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
		int n,m;
		cin>>n>>m;
		disjoint SET(n);
		int owe[n],sum[n]={0};
		for(int i=0 ; i<n ; i++)
			cin>>owe[i];

		for(int i=0 ; i<m ; i++)
		{
			int a,b;
			cin>>a>>b;
			SET.merge(a,b);
		}
		for(int i=0 ; i<n ; i++)
		{
			sum[SET.find(i)]+=owe[i];
		}
		bool flag=1;
		for(int i=0 ; i<n ; i++)
		{
			if(sum[i])
			{
				flag=0;
				break;
			}
		}
		cout<<(flag?"POSSIBLE":"IMPOSSIBLE")<<"\n";
	}
	return 0;
}
