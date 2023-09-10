#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct coord
{
	int X,Y;
	coord(int x,int y)
	{
		this->X = x;
		this->Y = y;
	}
	double dis(const coord &a)
	{
		return sqrt((this->X-a.X)*(this->X-a.X) + (this->Y-a.Y)*(this->Y-a.Y));
	}
};

struct edge
{
	int S,D;
	double V;
	edge(int s, int d, double v)
	{
		this->S = s;
		this->D = d;
		this->V = v;
	}
	bool operator<(const edge& a) const {
        return this->V < a.V;
    }
};

class disjoint
{
private:
	vector<int> Set;
public:
	disjoint(int n)
	{
		Set.reserve(n);
		for (int i=0 ; i<n ; i++)
			Set[i] = i;
	}
	int find(int n)
	{
		return Set[n]==n? n: (Set[n]=this->find(Set[n]));
	}
	void join(int n1,int n2)
	{
		Set[this->find(n1)] = this->find(n2);
	}
	bool same(int n1,int n2)
	{
		return this->find(n1)==this->find(n2);
	}
};

vector<edge> E;

double kruskal(int n)
{
	sort(E.begin(),E.end());
	disjoint K(n);
	int len = E.size();
	for(int i=0 ; i<len ; i++)
	{
		edge cur = E[i];
		if(!K.same(cur.S,cur.D))
		{
			K.join(cur.S,cur.D);
		}

		if(K.same(0,1))
		{
			return cur.V;
		}
	}
}

int main(int argc, char const *argv[])
{
	int n,t=0;
	while(cin>>n)
	{
		if(!n)break;

		E.clear();
		vector<coord> C;

		int x,y;
		for(int i=0 ; i<n ; i++)
		{
			cin>>x>>y;
			C.push_back(coord(x,y));
		}

		for(int i=0 ; i<n ; i++)
		{
			for(int j=i+1 ; j<n ; j++)
			{
				E.push_back(edge(i,j,C[i].dis(C[j])));	
			}
		}
		cout<<"Scenario #"<<++t;
		printf("\nFrog Distance = %.3lf\n\n", kruskal(n));
	}
	return 0;
}