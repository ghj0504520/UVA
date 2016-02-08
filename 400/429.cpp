#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <sstream>

using namespace std;

struct data
{
	string s;
	int cnt;

	data(string in,int c)
	{
		s=in,cnt=c;
	}
};
set<string> DICT;
map<string,int> table;

int BFS(string s,string d)
{
	queue<data>bfs;
	bfs.push(data(s,0));
	table.insert(std::pair<string,int>(s,1));

	while(bfs.size())
	{
		data cur=bfs.front();
		bfs.pop();

		if(cur.s==d)return cur.cnt;

		string now;
		int len=cur.s.size();
		for(int i=0 ; i<len ; i++)
		{
			now=cur.s;
			for(char c='a' ; c<='z' ; c++)
			{
				now[i]=c;

				if(DICT.count(now))
				{
					if(table.find(now)==table.end())
					{
						bfs.push(data(now,cur.cnt+1));
						table.insert(std::pair<string,int>(now,1));						
					}
				}
			}
		}
	}
	return -1;
}

int main()
{
	int T;
	cin>>T;
	for(int t=0 ; t<T ; t++)
	{
		if(t)cout<<"\n";
		DICT.clear();
		string line;
		while(cin>>line)
		{
			if(line=="*")break;
			DICT.insert(line);
		}
		cin.ignore();
		string seq,start,dest;
		while(getline(cin,seq))
		{
			if(seq=="")break;

			stringstream buf(seq);
			buf>>start>>dest;
			table.clear();
			cout<<start<<" "<<dest<<" "<<BFS(start,dest)<<"\n";
			
		}
	}
	return 0;
}