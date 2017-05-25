#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

struct disjoint
{
	vector<int> node;
	disjoint(int n)
	{
		node.resize(30);
		for(int i=1 ; i <= n ; i++)
			node[i]=i;
	}
	int find(int x)
	{
		return node[x]==x?x:(node[x]=find(node[x]));
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
	void merge(int x,int y)
	{
		node[find(x)]=find(y);
	}
};

struct edge
{
	int s,d,v;

	edge(int a,int b,int c):s(a),d(b),v(c)
	{}

	bool operator<(const edge& pos)const
	{
		return v<pos.v;
	}
};
vector<edge> elist;

void kruskal(int n)
{
	stable_sort(elist.begin(),elist.end());
	disjoint s(n);
	int len=elist.size();
	for(int i=0 ; i<len ; i++)
	{
		if(!s.same(elist[i].s,elist[i].d))
		{
			s.merge(elist[i].s,elist[i].d);
			cout<<(char)(elist[i].s+'A')<<"-"<<(char)(elist[i].d+'A')<<" "<<elist[i].v<<"\n";	
		}
	}
}

int main()
{
	int T;
	cin>>T;
	for(int t=0 ; t<T ; t++)
	{
		cout<<"Case "<<t+1<<":\n";
		int n;
		cin>>n;
		string in;
		elist.clear();
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>in;
				if(j<n-1)in[in.size()-1]='\0';
				stringstream buf(in);
				int v;
				buf>>v;
				if(v)elist.push_back(edge(i,j,v));
			}
		}kruskal(n);
	}
	return 0;
}