#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	map <string,string>dict;
	string english,foreign;
	char in[10000];
	while(cin.getline(in,9999))
	{
		if(in[0]=='\0')break;
		char in1[1000],in2[1000];
		sscanf(in,"%s %s",in1,in2);
		english=in1;
		foreign=in2;
		//dict[foreign]=english;
		dict.insert(pair<string,string>(foreign,english));
	}
	map <string,string>::iterator it;
	string query;
	while(cin>>query)
	{
		it=dict.find(query);
		if(it==dict.end())
		{
			cout<<"eh\n";
		}
		else
		{
			cout<<dict[query]<<'\n';
			//cout<<it->second<<'\n';
		}
	}
	return 0;
}
