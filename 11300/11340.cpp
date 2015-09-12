#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int numT;
		cin>>numT;
		map<char,int>cost;
		for(int i=0 ; i<numT ; i++)
		{
			char c;
			int v;
			cin>>c>>v;
			cost[c]=v;
		}
		int numL;
		cin>>numL;
		cin.ignore();
		string line;
		int ans=0;
		for(int i=0 ; i<numL ; i++)
		{
			getline(cin,line);
			int len=line.size();
			for(int j=0 ; j<len ; j++)
			{
				ans+=cost[ line[j] ];
			}
		}
		printf("%.2lf$\n", (double)ans/100);
	}
	return 0;
}