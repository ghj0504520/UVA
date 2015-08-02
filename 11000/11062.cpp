#include <iostream>
#include <cctype>
#include <sstream>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	string All="",tmp;
	while(cin>>tmp)
	{
		int len=tmp.size();
		if(tmp[len-1]=='-')
		{
			tmp.resize(len-1);
		}
		else
		{
			tmp+=' ';
		}
		for(int i=0 ; i<len ; i++)
		{
			if(isalpha(tmp[i])&&tmp[i]!='-')
			{
				tmp[i]=tolower(tmp[i]);
			}
			else if(!isalpha(tmp[i])&&tmp[i]!='-')
			{
				tmp[i]=' ';
			}
		}
		All+=tmp;
	}
	stringstream buf(All);
	set<string>dict;
	while(buf>>tmp)
	{
		if(!dict.count(tmp))
			dict.insert(tmp);
	}
	set<string>::iterator it;
	for(it=dict.begin();it!=dict.end();it++)
	{
		cout<<*it<<"\n";
	}
	return 0;
}