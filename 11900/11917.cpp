#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int r;
	cin>>r;
	for(int t=0 ; t<r ; t++)
	{
		int num;
		cin>>num;
		map<string,int>table;
		for(int i=0 ; i<num ;i++)
		{
			string course;
			int delay;
			cin>>course>>delay;
			table[course]=delay;
		}
		int day;
		cin>>day;
		string help;
		cin>>help;
		cout<<"Case "<<t+1<<": ";
		if(!table[help]||table[help]>day+5)
		{
			cout<<"Do your own homework!\n";
		}
		else if(table[help]<=day+5 &&table[help]>day)
		{
			cout<<"Late\n";
		}
		else
		{
			cout<<"Yesss\n";
		}
	}
}