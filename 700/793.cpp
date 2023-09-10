#include <iostream>
#include <cstdio>
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
		return ;
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

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	while(n--)
	{
		int node;
		cin>>node;

		Disjoint pc(node);

		string type;
		int S=0,F=0;
		getline(cin,type);
		while(getline(cin,type))
		{
			int p1,p2;
			if(type=="\0")
				break;
			sscanf(type.c_str(),"%*c %d %d",&p1,&p2);
			if(type[0]=='c')
			{
				pc.disjointUnion(p1,p2);
			}
			else if(type[0]=='q')
			{
				if(pc.disjointSame(p1,p2))
					S++;
				else F++;
			}
		}
		cout<<S<<","<<F<<"\n";
		if(n)cout<<"\n";
	}
	return 0;
}