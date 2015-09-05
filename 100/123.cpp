#include <iostream>
#include <map>
#include <cctype>
#include <sstream>
#include <set>

using namespace std;

set<string> Ignore;
multimap<string,string>KWIC;

struct sentence
{
	string input;
	string word[30];
	int Len;

	string stringPlus()
	{
		string sum="";
		for(int i=0 ; i<Len-2 ; i++)
			sum+=(word[i]+" ");
		sum+=word[Len-2];
		return sum;
	}
	void TOUP(string &in)
	{
		int len =in.size();
		for(int i=0  ;i<len ; i++)
			in[i]=toupper(in[i]);
	}
	void TOLOW(string &in)
	{
		int len =in.size();
		for(int i=0  ;i<len ; i++)
			in[i]=tolower(in[i]);
	}
	void initialize()
	{
		int len=input.size();
		for(int i=0 ; i<len ; i++)
			input[i]=tolower(input[i]);

		int idx=0;
		stringstream buf(input);
		while(buf>>word[idx++]);
		Len=idx;

		for(int i=0 ; i<Len-1 ; i++)
		{
			if(Ignore.find(word[i])==Ignore.end())
			{
				TOUP(word[i]);
				string cur=stringPlus();
				TOLOW(word[i]);
				KWIC.insert(std::pair<string,string>(word[i],cur));
			}
		}
	}
}data[300];

int main()
{
	ios::sync_with_stdio(0);
	string readin;
	while(cin>>readin)
	{
		if(readin=="::")break;
		Ignore.insert(readin);
	}
	cin.ignore();
	int i=0;
	while(getline(cin,readin))
	{
		data[i].input=readin;
		data[i].initialize();
		i++;
	}
	multimap<string,string>::iterator it;
	for(it=KWIC.begin() ; it!=KWIC.end() ; it++)
		cout<<it->second<<"\n";
	return 0;
}