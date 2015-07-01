#include <iostream>
#include <sstream>
#include <cstring>
#include <queue>
#define M 1001
using namespace std;

int pnum,cost[5],q;
string cmd[M];
int cur_line[M];
int var[30];
bool lock;
deque <int> ready;
queue <int> block;

void process(int pid)
{
	int round_time=q;
	while(round_time>0)
	{
		string cur_cmd=cmd[cur_line[pid]];
		if(cur_cmd[2]=='=')
		{
			stringstream buf(cur_cmd);
			int number;
			char ch,op;
			buf>>ch>>op>>number;
			var[ch-'a']=number;
			round_time-=cost[0];
		}
		else if(cur_cmd[0]=='p')
		{
			stringstream buf(cur_cmd);
			char ch;
			string tmp;
			buf>>tmp>>ch;
			cout<<pid+1<<": "<<var[ch-'a']<<'\n';
			round_time-=cost[1];
		}
		else if(cur_cmd[0]=='l')
		{
			if(lock)
			{
				block.push(pid);
				return ;
			}
			lock=1;
			round_time-=cost[2];
		}
		else if(cur_cmd[0]=='u')
		{
			lock=0;
			if(!block.empty())
			{
				ready.push_front(block.front());         //figure out
				block.pop();
			}
			round_time-=cost[3];
		}
		else if(cur_cmd[0]=='e')
		{
			round_time-=cost[4];
			return ;
		}
		cur_line[pid]++;
	}
	ready.push_back(pid);
}

int main()
{
	ios::sync_with_stdio(0);
	
	int n;
	cin>>n;
	for(int t=0 ; t<n ; t++)
	{
		if(t)cout<<'\n';
		cin>>pnum>>cost[0]>>cost[1]>>cost[2]>>cost[3]>>cost[4]>>q;
		memset(var,0,sizeof(var));
		int line=0;
		for(int i=0 ; i<pnum ; i++)
		{
			getline(cin,cmd[line]);
			cur_line[i]=line++;
			while(cmd[line-1]!="end")
				getline(cin,cmd[line++]);
				
			ready.push_back(i);
		}
		while(!ready.empty())
		{
			int pid=ready.front();
			ready.pop_front();
			process(pid);
		}
	}
	return 0;
}
