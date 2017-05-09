#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

struct disjoint
{
	vector<int > set;

	disjoint(int n)
	{
		for(int i=0 ; i<=n ; i++)
		{
			set.push_back(i);
		}
	}

	int find(int x)
	{
		return set[x]==x? x: ( set[x]=find(set[x]) );
	}
	void merge(int x,int y)
	{
		set[x]=y;
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
};

int main()
{
	int T;
	cin>>T;
	int op,a,b;
	disjoint SET(2*T);
	while(cin>>op>>a>>b)
	{
		if(!op&&!a&&!b)break;
		
		int fa=SET.find(a),fb=SET.find(b),ea=SET.find(a+T),eb=SET.find(b+T);
		if(op==1)
		{
			if(fa==eb)cout<<"-1\n";
			else{
				SET.merge(fa,fb);
				SET.merge(ea,eb);
			}
		}else if(op==2)
		{
			if(fa==fb)cout<<"-1\n";
			else{
				SET.merge(fa,eb);
				SET.merge(ea,fb);	
			}
		}else if(op==3)
		{
			cout<<(fa==fb?"1":"0")<<"\n";
		}else if(op==4)
		{
			cout<<(fa==eb?"1":"0")<<"\n";
		}

	}
	return 0;
}
