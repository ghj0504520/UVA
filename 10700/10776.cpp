#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
string in;
char sol[30];
bool check[30];

void DFS(int Pos,int All,int Get,int index)
{
	if(Pos==Get)
	{
		cout<<sol<<"\n";
		return ;
	}
	else
	{
		int repeat='\0';
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
	int Get,All;
	while(cin>>in>>Get)
	{
		All=in.size();
		sort(in.begin(),in.end());
		memset(sol,0,sizeof(sol));
		memset(check,0,sizeof(check));
		DFS(0,All,Get,0);
	}
	return 0;
}