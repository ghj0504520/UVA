#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <sstream>

using namespace std;

map <string,vector<string> >HASH;
map <string,int>vis;
int p,n;

void token(string in)
{
	int s=0,d;
	int len=in.size();
	string cut;
	vector<string> author;
	for(d=0 ; d<len ; d++)
	{
		
		if(in[d]==','&&in[d-1]=='.')
		{
			cut=in.substr(s,d-s);
			s=d=d+2;
			author.push_back(cut);
		}
		else if(in[d]==':'&&in[d-1]=='.')
		{
			cut=in.substr(s,d-s);
			author.push_back(cut);
			break;
		}
	}
	int Len=author.size();
	for(int i=0 ; i<Len ; i++)
		for(int j=i+1 ; j<Len ; j++)
		{
			HASH[ author[i] ].push_back(author[j]);
			HASH[ author[j] ].push_back(author[i]);
		}
}

void BFS(string S)
{
	queue<string>bfs;
	bfs.push(S);
	vis.insert(std::pair<string,int>(S,0));

	while(bfs.size())
	{
		string cur=bfs.front();
		bfs.pop();
		
		int len=HASH[cur].size();
		for(int i=0 ; i<len ; i++)
		{
			string next=HASH[cur][i];
			if(!vis.count(next))
			{
				bfs.push(next);
				vis.insert(std::pair<string,int>(next,vis[cur]+1));
			}
		}
		
	}

}

int main()
{
	int T;
	cin>>T;
	for (int t=0; t<T; ++t)
	{
		cout<<"Scenario "<<t+1<<"\n";
		HASH.clear();
		vis.clear();

		cin>>p>>n;
		cin.ignore();

		string line;
		for(int i=0 ; i<p ; i++)
		{
			getline(cin,line);
			token(line);
		}

		BFS("Erdos, P.");
		string query;
		for(int i=0 ; i<n ; i++)
		{
			getline(cin,query);
			cout<<query<<" ";
			if(vis.count(query))
				cout<<vis[query]<<"\n";
			else cout<<"infinity\n";
		}
	}
	return 0;
}