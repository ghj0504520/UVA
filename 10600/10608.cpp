#include <iostream>
#include <vector>
using namespace std;
 
class Disjoint
{
private:
	vector<int> disjointSet, setNum;
public:
	Disjoint(int n)
	{
		this->disjointSet.reserve(n+1);
		this->setNum.reserve(n+1);
		for(int i=0 ; i<=n ; i++)
		{
			this->disjointSet[i]=i;
			this->setNum[i]=1;
		}
	}
	int disjointUnion(int a,int b)
	{
		int sum = this->setNum[this->disjointFind(a)]+this->setNum[this->disjointFind(b)];
		this->disjointSet[this->disjointFind(a)] = this->disjointFind(b);
		this->setNum[this->disjointFind(a)]=sum;
		this->setNum[this->disjointFind(b)]=sum;
		return sum;
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
	int n,m,t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
 
		Disjoint friendShip(n);
 
		int p1,p2;
		int maxNum = 1;
		while(m--)
		{
			cin>>p1>>p2;
 
			if(!friendShip.disjointSame(p1,p2))
			{
				int tmpMax = friendShip.disjointUnion(p1,p2);
				if(tmpMax > maxNum) maxNum = tmpMax;
			}
		}cout<<maxNum<<"\n";
	}
}
