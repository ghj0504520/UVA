#include <iostream>
#include <vector>
using namespace std;

class DJS
{
private:
	vector<int> S,N;
public:
	DJS(int n)
	{
		this->S.reserve(n);
		this->N.reserve(n);
		for (int i = 0; i < n; ++i)
		{
			S[i] = i;
			N[i] = 1;
		}
	}
	void Union(int a, int b)
	{
		int sum = this->N[this->Find(a)]+this->N[this->Find(b)];
		this->S[ this->Find(a) ] = this->Find(b);
		this->N[this->Find(a)]=sum;
		this->N[this->Find(b)]=sum;
	}
	bool Same(int a, int b)
	{
		return this->Find(a) == this->Find(b);
	}
	int Find(int a)
	{
		return (this->S[a] == a)? a:(this->S[ a ]=this->Find( this->S[ a ] ));
	}
	int SetNum(int a)
	{
		return this->N[this->Find(a)];
	}
};
int main(int argc, char const *argv[])
{
	int n,m;
	while(cin>>n>>m)
	{
		if(!n&&!m)break;
		int num,id1,id2;
		DJS djs(n);
		for (int i = 0; i < m; ++i)
		{
			cin>>num;
			cin>>id1;
			for (int j = 1; j < num; ++j)
			{
				cin>>id2;
				if(!djs.Same(id1,id2))
					djs.Union(id1,id2);
			}
		}
		cout<<djs.SetNum(0)<<'\n';
	}
	return 0;
}