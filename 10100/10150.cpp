#include <iostream>
#include <map>
#include <set>
#include <queue>

using namespace std;

set<string> DICT;
map<string,string>table;

struct data
{
	string cur;
	int cnt;
	data(string c,int ct)
	{
		cur=c,cnt=ct;
	}
};

string change(string s,int pos,char c)
{
	s[pos]=c;
	return s;
}

void print(string s)
{
	if(table[s]=="***")
	{
		cout<<s<<"\n";
		return ;
	}
	else
	{
		print(table[s]);
		cout<<s<<"\n";
	}
}

int BFS(string s,string d)
{
	queue<data>bfs;
	bfs.push(data(s,0));
	table[s]="***";

	while(!bfs.empty())
	{
		data current=bfs.front();
		bfs.pop();

		if(current.cur==d)
		{
			print(current.cur);
			return current.cnt;
		}

		string now;
		int len=current.cur.size();
		for(int i=0 ; i<len ; i++)
		{
			now=current.cur;
			for(char c='a' ; c<='z' ; c++)
			{
				string next=change(now,i,c);
				if(DICT.count(next)&&table.find(next)==table.end())
				{
					table[next]=current.cur;
					bfs.push(data(next,current.cnt+1));
				}
			}
		}
	}
	return -1;
}

int main()
{
	string in;
	while(getline(cin,in))
	{
		if(in=="")break;

		DICT.insert(in);
	}

	int t=0;
	string start,dest;
	while(cin>>start>>dest)
	{
		if(t++)cout<<"\n";
		table.clear();
		int ans=BFS(start,dest);
		if(ans==-1)cout<<"No solution.\n";
	}
	return 0;
}