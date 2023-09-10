#include <iostream>
#include <vector>
#include <map>
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
	while(cin>>n>>m)
	{
		if(!n&&!m)break;
 
		Disjoint chain(n);
		map<string,int> creature;
 
 		string c1,c2;
 		int cnt=0;
 		while(n--)
 		{
 			cin>>c1;
 			cnt++;
 			creature[c1] = cnt;
 		}
 
		int maxNum = 1;
		while(m--)
		{
			cin>>c1>>c2;
 
			if(!chain.disjointSame(creature[c1],creature[c2]))
			{
				int tmpMax = chain.disjointUnion(creature[c1],creature[c2]);
				if(tmpMax > maxNum) maxNum = tmpMax;
			}
		}cout<<maxNum<<"\n";
	}
}