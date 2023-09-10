#include <iostream>
#include <map>
using namespace std;

map <char,char>table;
void init()
{
	table['A']=table['B']=table['C']='2';
	table['D']=table['E']=table['F']='3';
	table['G']=table['H']=table['I']='4';
	table['J']=table['K']=table['L']='5';
	table['M']=table['N']=table['O']='6';
	table['P']=table['R']=table['S']='7';
	table['T']=table['U']=table['V']='8';
	table['W']=table['X']=table['Y']='9';
}
string normalNumber(string in)
{
	int l = in.length();
	for (int i = 0; i < l; ++i)
	{
		if(in[i]=='-')
		{
			in.erase(i,1);
			i--;
			l--;
		}
		else if(in[i]>='A'&&in[i]<='Y')
			in[i] = table[in[i]];
	}
	in.insert(3,"-");
	return in;
}

int main()
{
	int t;
	cin>>t;
	init();
	while(t--)
	{
		int num;
		string phone;
		map<string,int> directory;

		cin>>num;
		for (int i = 0; i < num; ++i)
		{
			cin>>phone;
			directory[normalNumber(phone)]++;
		}

		map<string,int>::iterator it;
		bool f=0;
		for (it=directory.begin() ; it!=directory.end() ; ++it)
		{
			if(it->second > 1)
			{
				f=1;
				cout<<it->first<<" "<<it->second<<'\n';
			}
		}
		if(!f)cout<<"No duplicates.\n";

		if(t)cout<<"\n";
	}
}