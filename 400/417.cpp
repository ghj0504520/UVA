#include <iostream>
#include <map>

using namespace std;

map<string,int>table;
int count;
void createStringTable(string line,int finishDigit)
{
	if(line.length()==finishDigit)
	{
		table[line]=++count;
		return ;
	}
	else
	{
		char cur;
		if(line=="")	cur='a';
		else 	cur=line[line.size()-1]+1;

		for(int c=cur ; c<='z' ; c++)
			createStringTable(line+(char)c,finishDigit);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	count=0;
	for(int i=0; i<5 ; i++)
		createStringTable("",i+1);
	string query;
	while(cin>>query)
	{
		if(table.find(query)!=table.end())
			cout<<table[query]<<"\n";
		else	cout<<"0\n";
	}
	return 0;
}