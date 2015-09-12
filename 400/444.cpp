#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

map<char,int>encode;
map<int,char>decode;

void init()
{
	for(int i='a' ; i<='z' ; i++)
	{
		encode.insert(std::pair<char,int>((char)i,(int)i));
		decode.insert(std::pair<int,char>((int)i,(char)i));
	}
	for(int i='A' ; i<='Z' ; i++)
	{
		encode.insert(std::pair<char,int>((char)i,(int)i));
		decode.insert(std::pair<int,char>((int)i,(char)i));
	}
	char c;
	c=' ';
	encode.insert(std::pair<char,int>((char)c,(int)c));
	decode.insert(std::pair<int,char>((int)c,(char)c));
	c='!';
	encode.insert(std::pair<char,int>((char)c,(int)c));
	decode.insert(std::pair<int,char>((int)c,(char)c));
	c=',';
	encode.insert(std::pair<char,int>((char)c,(int)c));
	decode.insert(std::pair<int,char>((int)c,(char)c));
	c='.';
	encode.insert(std::pair<char,int>((char)c,(int)c));
	decode.insert(std::pair<int,char>((int)c,(char)c));
	c=':';
	encode.insert(std::pair<char,int>((char)c,(int)c));
	decode.insert(std::pair<int,char>((int)c,(char)c));
	c=';';
	encode.insert(std::pair<char,int>((char)c,(int)c));
	decode.insert(std::pair<int,char>((int)c,(char)c));
	c='?';
	encode.insert(std::pair<char,int>((char)c,(int)c));
	decode.insert(std::pair<int,char>((int)c,(char)c));
}

int main()
{
	ios::sync_with_stdio(0);
	string in;
	init();
	while(getline(cin,in))
	{
		string ans="";
		if(in[0]>='0'&&in[0]<='9')
		{
			reverse(in.begin(),in.end());
			int len=in.size(),curCode=0;
			for (int i = 0; i < len; ++i)
			{
				curCode=curCode*10+(in[i]-'0');

				if(decode.count(curCode))
				{
					ans+=decode[curCode];
					curCode=0;
				}
			}
		}
		else
		{
			int len=in.size();
			for (int i = 0; i < len; ++i)
			{
				int val=encode[in[i]];
				string tmp;
				stringstream buf;
				buf<<val;
				buf>>tmp;
				ans+=tmp;
			}
			reverse(ans.begin(),ans.end());
		}
		cout<<ans<<"\n";
	}
	return 0;
}