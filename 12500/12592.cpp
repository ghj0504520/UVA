#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int num;
	cin>>num;
	string a,b;
	map<string,string>table;
	cin.ignore();
	for(int i=0 ; i<num ;i++)
	{
		getline(cin,a);
		getline(cin,b);
		table[a]=b;
	}
	cin>>num;
	cin.ignore();
	for(int i=0; i<num ;i++)
	{
		getline(cin,a);
		cout<<table[a]<<"\n";
	}
	return 0;
}