#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

bool prime[1001];
void prime_init()
{
	memset(prime,0,sizeof(prime));
	prime[0]=1;
	prime[1]=1;
	for(int i=2; i<=1000 ;i++)
		if(!prime[i])
			for(int j=i+i ; j<=1000 ; j+=i)
				prime[j]=1;
}

vector<int>factor;
vector<int> find_factor(int q)
{
	factor.clear();
	if(!(q%2) && q>2)factor.push_back(2);
	if(q>3)
	{
		for(int i=3; i<q ; i+=2)
		{
			if(!prime[i]&&!(q%i))
				factor.push_back(i);
		}
	}
	return factor;
}

int BFS(int Start,int finish)
{
	map<int,int>table;
	queue<std::pair<int ,vector<int> > >bfs;
	int step=0;
	vector<int> pset;

	pset=find_factor(Start);
	bfs.push(std::pair<int ,vector<int> >(Start,pset));
	table.insert(std::pair<int,int>(Start,step));
	while(!bfs.empty())
	{
		int cur=bfs.front().first;
		step=table[cur];
		pset=bfs.front().second;
		bfs.pop();

		if(cur==finish)return step;
		
		for(int i=0 ; i<pset.size();i++)
		{
			int now=cur+pset[i];
			if(table.find(now)==table.end() && now <= finish )
			{
				vector<int> nset=find_factor(now);
				bfs.push(std::pair<int ,vector<int> >(now,nset));
				table.insert(std::pair<int,int>(now,step+1));
			}
		}
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(0);
	int q,d,t=0;
	prime_init();
	while(cin>>q>>d)
	{
		if(!q&&!d)break;
		cout<<"Case "<<++t<<": "<<BFS(q,d)<<"\n";
	}
	return 0;
}