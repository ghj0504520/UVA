#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	string word;
	map < string,string > table;
	while(cin>>word)
	{
		if(word=="XXXXXX")
			break;
		string pres=word;
		sort(word.begin(),word.end());
		table.insert(pair< string,string > (pres,word));
	}
	string query;
	while(cin>>query)
	{
		if(query=="XXXXXX")
			break;
		sort(query.begin(),query.end());
		
		map <string,string> ::iterator it;
		bool check =0;
		for(it=table.begin();it!=table.end();it++)
		{
			if(it->second==query)
			{
				cout<<it->first<<'\n';
				check =1;
			}
		}
		if(!check)
			cout<<"NOT A VALID WORD\n";
		cout<<"******\n";
		
	}
	return 0;
}
