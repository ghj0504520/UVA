#include <iostream>
#include <vector>
using namespace std;

class Disjoint
{
private:
	vector<int> disjointSet;
public:
	Disjoint(int n)
	{
		this->disjointSet.reserve(n+1);
		for(int i=0 ; i<=n ; i++)
			this->disjointSet[i]=i;
	}
	void disjointUnion(int a,int b)
	{
		this->disjointSet[this->disjointFind(a)] = this->disjointFind(b);
		return;
	}
	int disjointFind(int a)
	{
		return (this->disjointSet[a] == a? a:(this->disjointSet[a] = this->disjointFind(this->disjointSet[a])) );
	}
	bool disjointSame(int a,int b)
	{
		return this->disjointFind(a) == this->disjointFind(b);
	}
};

int main()
{
	int n,m,t=0;
	while(cin>>n>>m)
	{
		if(!n&&!m)break;

		Disjoint religions(n);

		int p1,p2;
		int maxDiff =n;
		while(m--)
		{
			cin>>p1>>p2;
			
			if(!religions.disjointSame(p1,p2))
			{
				maxDiff--;
				religions.disjointUnion(p1,p2);
			}
		}cout<<"Case "<<++t<<": "<<maxDiff<<"\n";
	}
}