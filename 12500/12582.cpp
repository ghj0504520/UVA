#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
	int num;
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cout<<"Case "<<i+1<<'\n';
		string route;
		cin>>route;
		int table[256]={0};
		int len=route.length();
		stack <char> DFS;
		for(int j=0;j<len;j++)
		{
			if(DFS.empty())
			{
				DFS.push(route[j]);
			}
			else
			{
				if(DFS.top()==route[j])
				{
					DFS.pop();
				}
				else
				{
					table[(int)DFS.top()]++;
					DFS.push(route[j]);
					table[(int)DFS.top()]++;
				}
			}
		}
		for(int ch='A';ch<='Z';ch++)
		{
			if(table[ch])
			{
				printf("%c = %d\n",ch,table[ch]);
			}
		}
	}
	return 0;
}
