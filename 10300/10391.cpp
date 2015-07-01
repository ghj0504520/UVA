#include <iostream>
#include <set>
using namespace std;

string word[150000];
set <string> table;

int main()
{
	ios::sync_with_stdio(0);
	int pos=0;
	while(cin>>word[pos])
	{
		table.insert(word[pos]);
		pos++;
	}
	string s1,s2;
	for(int i=0 ; i<pos ; i++)
	{
		int len=word[i].size();
		for(int j=1 ; j<len-1 ; j++)
		{
			s1=word[i].substr(0,j);
			s2=word[i].substr(j);
			if(table.count(s1)&&table.count(s2))
			{
				cout<<word[i]<<'\n';
				break;								//figure out
			}
		}
	}
	return 0;
}
