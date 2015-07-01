#include <iostream>
#include <set>
#include <cctype>
#include <cstdio>
#include <sstream>
using namespace std;

string mod(string line)
{
	int len=line.length();
	for(int i=0 ; i<len ; i++)
	{
		if(!isalpha(line[i]))
			line[i]=' ';
	}
	return line;
}

string tolow(string in)
{
	int len=in.length();
	for(int i=0 ; i<len ; i++)
	{
		in[i]=tolower(in[i]);
	}
	return in;
}

int check(string in,set<string> t)
{
	stringstream buf(in);
	int ans=0;
	string w;
	while(buf>>w)
	{
		if(t.count(tolow(w)))
			ans++;
	}
	return ans;
}

int main()
{
	int n,m,t=0;
	while(cin>>n>>m)
	{
		string key;
		set <string> table;
		for(int i=0 ; i<n ; i++)
		{
			cin>>key;
			table.insert(tolow(key));
		}
		string sent[50],pre[50];
		int data[50];
		getchar();
		for(int i=0 ; i<m ; i++)
		{
			getline(cin,sent[i]);
			pre[i]=sent[i];
			sent[i]=mod(sent[i]);
		}
		for(int i=0 ; i<m ; i++)
		{
			data[i]=check(sent[i],table);
		}
		int max=0;
		for(int i=0 ; i<m ; i++)
		{
			if(data[i]>max)
				max=data[i];
		}
		cout<<"Excuse Set #"<<++t<<"\n";
		for(int i=0 ; i<m ; i++)
		{
			if(data[i]==max)
				cout<<pre[i]<<'\n';
		}
		cout<<"\n";
	}
	return 0;
}
