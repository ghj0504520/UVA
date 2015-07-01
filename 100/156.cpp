#include <cstdio>
#include <iostream>
#include <map>
#include <cctype>
#include <algorithm>
using namespace std;

struct WORD
{
	string pre,mod;
};
void modify(string &in)
{
	int len=in.size();
	for(int i=0;i<len;i++)
	{
		in[i]=tolower(in[i]);
	}
	sort(in.begin(),in.end());
}
bool cmp(const WORD &i,const WORD &j)
{
	return i.pre<j.pre;
}
int main()
{
	string word;
	map<string,int> dict;
	WORD words[100000];
	int pos=0;
	while(cin>>word)
	{
		if(word=="#")break;
		words[pos].pre=word;
		modify(word);
		words[pos].mod=word;
		
		map<string,int>::iterator it;
		it=dict.find(words[pos].mod);
		if(it==dict.end())
		{
			dict.insert(pair<string,int>(words[pos].mod,0));
		}
		else
		{
			it->second++;
		}
		pos++;
	}
	sort(words,words+pos,cmp);
	for(int i=0;i<pos;i++)
	{
		if(!dict[words[i].mod])
			cout<<words[i].pre<<'\n';
	}
	return 0;
}
