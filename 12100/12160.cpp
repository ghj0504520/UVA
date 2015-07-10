#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
	int L,U,R,t=0;
	while(cin>>L>>U>>R)
	{
		if(!L&&!U&&!R)break;
		int button[11];
		for(int i=0 ; i<R; i++)
			cin>>button[i];
		queue<int> bfs;
		map<int,int> table;
		int step=0;
		int success=0;
		bfs.push(L);
		table.insert(std::pair<int ,int >(L,step));
		while(!bfs.empty())
		{
			int cur=bfs.front();
			bfs.pop();
			step=table[cur];
			if(cur==U)
			{
				success=1;
				break;
			}
			for(int i=0 ; i<R ; i++)
			{
				int now=(cur+button[i])%10000;
				if(table.find(now)==table.end())
				{
					bfs.push(now);
					table.insert(std::pair<int ,int >(now,step+1));
				}
			}

		}
		cout<<"Case "<<++t<<": ";
		if(success)	cout<<step<<"\n";
		else		cout<<"Permanently Locked\n";
	}
	return 0;
}