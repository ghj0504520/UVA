#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
int sum;

void DFS(int cur,vector<int> n[],bool v[])
{
	v[cur]=1;
	int len=n[cur].size();
	for(int i=0 ; i<len ; i++)
	{
		if(!v[n[cur][i]])
		{
			sum++;
			DFS(n[cur][i],n,v);
		}
	}
}
int main()
{
	//freopen("out","w",stdout);
	int num;
	cin>>num;
	for(int t=0 ; t<num ; t++)
	{
		int Mnode,side,knock;
		cin>>Mnode>>side>>knock;
		
		vector<int> node[10000+5];
		for(int i=0 ; i<side ; i++)
		{
			int start,dest;
			cin>>start>>dest;
			node[start].push_back(dest);
		}
		bool visit[10000+5];
		memset(visit,0,sizeof(visit));
		sum=0;
		for(int i=0 ; i<knock ; i++)
		{
			int number;
			cin>>number;
			if(!visit[number])sum++;
			DFS(number,node,visit);
		}
		/*
		for(int i=1;i<=Mnode;i++)
			if(visit[i])
				sum++;
		*/
		cout<<sum<<'\n';
	}
	return 0;
}
