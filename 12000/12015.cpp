#include <iostream>
#include <map>

using namespace std;

int main()
{
	multimap<int,string>table;
	int num;
	cin>>num;
	for(int i=0 ; i<num ; i++)
	{
		cout<<"Case #"<<i+1<<":\n";
		table.clear();
		for(int j=0 ; j<10 ; j++)
		{
			int n;
			string u;
			cin>>u>>n;
			table.insert(std::pair<int,string>(n,u));
		}
		int max=0;
		multimap<int,string>::iterator it;
		for(it=table.begin() ; it!=table.end() ; it++)
		{
			max= it->first > max ? it->first : max;
		}
		for(it=table.begin() ; it!=table.end() ; it++)
		{
			if(it->first==max)
				cout<<it->second<<"\n";
		}
	}
	return 0;
}