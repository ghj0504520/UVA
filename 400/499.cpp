#include <iostream>
#include <cctype>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	string seq;
	while(getline(cin,seq))
	{
		int len=seq.size();
		map<char,int>table;
		for(int i=0;i<len;i++)
		{
			if(isalpha(seq[i]))
			{
				if(table.find(seq[i])==table.end())
				{
					table.insert(std::pair<char,int>(seq[i],1));
				}
				else
				{
					table[seq[i]]++;
				}
			}
		}
		int M=-1;
		for(map<char,int>::iterator it =table.begin() ; it!=table.end();it++)
		{
			if(it->second > M)
			{
				M=it->second;
			}
		}
		for(map<char,int>::iterator it =table.begin() ; it!=table.end();it++)
		{
			if(it->second==M)
			{
				cout<< it->first;
			}
		}
		cout<<" "<<M<<"\n";
	}
	return 0;
}