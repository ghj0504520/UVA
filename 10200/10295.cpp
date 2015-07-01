#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int num,job;
	cin>>num>>job;
	map <string,int> dict;
	for(int i=0 ; i<num ; i++)
	{
		string word;
		int weight;
		cin>>word>>weight;
		dict.insert(pair<string,int>(word,weight));
	}
	string script;
	int sum=0;
	while(cin>>script)
	{
		if(script==".")
		{
			cout<<sum<<'\n';
			sum=0;
		}
		else
		{
			map <string,int> ::iterator it;
			it=dict.find(script);
			if(it!=dict.end())
			{
				sum+=dict[script];
			}
		}
	}
	return 0;
}
