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

struct coord
{
	int X,Y;
	coord(int x,int y)
	{
		X=x,Y=y;
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

double dis(int x1,int y1,int x2,int y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int Kruskal()
{	
	vector<coord> data;
	int n;
    cin>>n;
    for(int i=0 ; i<n ; i++)
	{
		int x,y;
		cin>>x>>y;
		data.push_back( coord(x,y) );
	}

	vector<edge> edgeList;
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			if(i!=j)
			{
				edgeList.push_back( edge(i,j, dis(data[i].X,data[i].Y,data[j].X,data[j].Y) ) );
			}
		}
	}

	//main algorithm
	int result=0;
	sort(edgeList.begin(),edgeList.end());
	int len=edgeList.size();
	disjoint S(n);

	int m;
	cin>>m;
	for(int i=0 ; i<m ; i++)
	{
		int s,d;
		cin>>s>>d;
		S.merge(s-1,d-1);
	}

	for(int i=0 ; i<len ; i++)
	{
		if(!S.same(edgeList[i].S,edgeList[i].D) )
		{
			S.merge(edgeList[i].S,edgeList[i].D);
			cout<<edgeList[i].S+1<<" "<<edgeList[i].D+1<<"\n";
            result=1;
		}
	}
	return result;
}

int main()
{
	int T,t=0;
    cin>>T;
	while(T--)
	{   
        if(t++)cout<<"\n";
        int need=Kruskal();
        if(!need)cout<<"No new highways need\n";
	}

	return 0;
}