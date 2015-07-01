#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int num;
	cin>>num;
	getchar();
	getchar();
	for(int i=0;i<num;i++)
	{
		if(i)cout<<'\n';
		map <string,int>data;
		map <string,int>::iterator it;
		string tree;
		int num=0;
		while(getline(cin,tree))
		{
			if(tree=="\0")
				break;
			it=data.find(tree);
			if(it==data.end())
			{
				data[tree]=1;
			}
			else
			{
				data[tree]++;
			}
			num++;
		}
		for(it=data.begin();it!=data.end();it++)
		{
			cout<<it->first;
			int count=it->second;
			//cout<<count<<'\n';
			printf(" %.4lf\n",(double)count/num*100);
		}
	}
}
