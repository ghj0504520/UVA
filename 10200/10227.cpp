#include <iostream>
#include <vector>
#include <cstdio>
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
	int n;
	cin>>n;
	while(n--)
	{
		int P,T;
		cin>>P>>T;
		getchar();
		int p[P+1][T+1]={0};
		string in;
		while(getline(cin,in))
		{
			if(in=="")break;
			int a,b;
			sscanf(in.c_str(),"%d %d",&a,&b);
			p[a][b]=1;
		}

		DJS djs(P+1);
		int ans=P;
		for (int i = 1; i <= P; ++i)
		{
			for (int j = 1; j <= P; ++j)
			{
				bool s=1;
				for (int t = 1; t <= T; ++t)
				{
					if(p[i][t]!=p[j][t])
					{
						s=0;break;
					}
				}

				if(s&&!djs.Same(i,j))
				{
					djs.Union(i,j);
					ans--;
				}
			}
		}
		cout<<ans<<"\n";
		if(n)cout<<"\n";
	}
	return 0;
}