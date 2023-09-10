#include <iostream>
#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct edge
{
	int S,D;
	int V;
	edge(int s, int d, int v)
	{
		this->S = s;
		this->D = d;
		this->V = v;
	}
	bool operator<(const edge& a) const {
        return this->V > a.V;
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

int kruskal(int v1,int v2,int n)
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

		if(K.same(v1,v2))
		{
			return cur.V;
		}
	}
}

int main(int argc, char const *argv[])
{
	int n,m,t=0;
	while(cin>>n>>m)
	{
		if(!n&&!m)break;

		E.clear();
		map<string,int> M;
		string S,D;
		int s,d,cnt=0,v;
		while(m--)
		{
			cin>>S>>D>>v;
			s = (M.find(S)==M.end())? (M[S]=cnt++):M[S];
			d = (M.find(D)==M.end())? (M[D]=cnt++):M[D];

			E.push_back(edge(s,d,v));
		}

		cin>>S>>D;
		
		cout<<"Scenario #"<<++t;
		printf("\n%d tons\n\n", kruskal(M[S],M[D],n));
	}
	return 0;
}