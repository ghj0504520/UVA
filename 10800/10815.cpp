#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <sstream>
#include <cctype>

using namespace std;
void string_modify(string *in)
{
	int len=(*in).length();
	for(int i=0;i<len;i++)
	{
		if(isalpha((*in)[i]))
			(*in)[i]=tolower((*in)[i]);
		else
			(*in)[i]=' ';
	}
}

int main()
{
	map <string,int> dict;
	string in;
	while(cin>>in)
	{
		string_modify(&in);
		stringstream s(in);
		string sub;
		/*
		while(s>>sub)                            //c++ string cut method one
		{
			//cout<<sub<<'\n';
			map <string,int>::iterator it;
			it=dict.find(sub);
			if(it==dict.end())
			{
				dict[sub]=1;
			}
		}
		*/
		while(getline(s,sub,' '))               //c++ string cut method two
		{
			//cout<<sub<<'\n';
			map <string,int>::iterator it;
			it=dict.find(sub);
			if(it==dict.end() &&sub!="\0")
			{
				dict[sub]=1;
			}
		}
	}
	for(map <string,int>::iterator flag=dict.begin();flag!=dict.end();flag++)
	{
		cout<<flag->first<<'\n';
	}
	return 0;
}
