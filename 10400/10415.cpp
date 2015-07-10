#include <iostream>
#include <cstring>
#include <map>
#include <cstdio>
using namespace std;

map<char, string> table;
int cnt[10];

void init_table()
{
	table.insert(std::pair<char,string>('c',"0111001111"));
	table.insert(std::pair<char,string>('d',"0111001110"));
	table.insert(std::pair<char,string>('e',"0111001100"));
	table.insert(std::pair<char,string>('f',"0111001000"));
	table.insert(std::pair<char,string>('g',"0111000000"));
	table.insert(std::pair<char,string>('a',"0110000000"));
	table.insert(std::pair<char,string>('b',"0100000000"));
	table.insert(std::pair<char,string>('C',"0010000000"));
	table.insert(std::pair<char,string>('D',"1111001110"));
	table.insert(std::pair<char,string>('E',"1111001100"));
	table.insert(std::pair<char,string>('F',"1111001000"));
	table.insert(std::pair<char,string>('G',"1111000000"));
	table.insert(std::pair<char,string>('A',"1110000000"));
	table.insert(std::pair<char,string>('B',"1100000000"));
}

int main()
{
	init_table();
	int count;
	cin>>count;
	getchar();
	for (int i = 0; i < count; ++i)
	{
		memset(cnt,0,sizeof(cnt));
		string in;
		getline(cin,in);
		int len=in.length();

		string f=table[in[0]];
		for(int p=0 ; p<10 ; p++)
		{
			if(f[p]=='1')
				cnt[p]++;
		}
		for(int j=1 ; j<len ; j++)
		{
			string pre=table[in[j-1]], cur=table[in[j]];
			for(int p=0 ; p<10 ; p++)
				if(pre[p]=='0'&&cur[p]=='1')cnt[p]++;
		}
		for (int j = 0; j < 9; ++j)
			cout<<cnt[j]<<" ";
		cout<<cnt[9]<<"\n";
	}
	return 0;
}
