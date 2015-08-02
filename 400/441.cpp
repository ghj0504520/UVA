#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
int in[15];
int sol[15];

void DFS(int Pos,int All,int Get,int index)
{
	if(Pos==Get)
	{
		for(int i=0 ; i<Get; i++)
		{
			if(i)cout<<" ";
			cout<<sol[i];
		}
		cout<<"\n";
		return ;
	}
	else
	{
		int repeat=-1;
		for(int i=index ; i<All ; i++)
		{
			if(repeat!=in[i])
			{
				repeat=in[i];
				sol[Pos]=in[i];
				DFS(Pos+1,All,Get,i+1);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	int All,t=0;
	while(cin>>All,All)
	{
		if(t)cout<<"\n";
		t++;
		for(int i=0 ; i<All;i++)
			cin>>in[i];
		sort(in,in+All);
		memset(sol,0,sizeof(sol));
		DFS(0,All,6,0);
	}
	return 0;
}