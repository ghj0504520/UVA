#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;
struct CAKE
{
	string name;
	int cost;
	CAKE(string s,int c)
	{
		name=s;
		cost=c;
	}

	bool operator<(const CAKE& pos)const
	{
		return cost<pos.cost||(cost==pos.cost&&name<pos.name);
	}
};

int main()
{
	int T;
	cin>>T;
	
	getchar();
	
	for(int t=0 ; t<T ; t++)
	{
		string name;
	
		getline(cin,name);
		int len=name.size();
		for(int i=0 ; i<len ; i++)
		{
			if(islower(name[i]))
				name[i]=toupper(name[i]);
		}cout<<name<<"\n";

		int m,n,b;
		cin>>m>>n>>b;
		map<string,int>hash;
		for(int i=0 ; i<m ; i++)
		{
			string n;
			int c;
			cin>>n>>c;
			hash[n]=c;
		}
		
		getchar();
		
		vector<CAKE> able;
		for(int i=0 ; i<n ; i++)
		{
			getline(cin,name);
			int e,cost=0,u;
			string en;
			cin>>e;

			for(int j=0 ; j<e ; j++)
			{
				cin>>en>>u;
				getchar();
				cost+=hash[en]*u;
			}
			if (cost<=b)
			{
				able.push_back(CAKE(name,cost));
			}
		}

		if(able.size()==0)
		{
			cout<<"Too expensive!\n";
		}
		else
		{
			sort(able.begin(),able.end());
			for (int i = 0; i < able.size(); ++i)
			{
				cout<<able[i].name<<"\n";
			}
		}cout<<'\n';
	}
	return 0;
}