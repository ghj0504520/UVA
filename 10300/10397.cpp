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

double dis(double x1,double y1,double x2,double y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

double Kruskal(int n)
{	
	vector<coord> data;
	for(int i=0 ; i<n ; i++)
	{
		double x,y;
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
	double result=0;
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
			result+=sqrt(edgeList[i].W);
		}
	}
	return result;
}

int main()
{
	int T;
	while(cin>>T)
	{
		printf("%.2lf\n",Kruskal(T));
	}

	return 0;
}