#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	for(int i=0 ; i<t ; i++)
	{
		string line;
		cin>>line;
		sort(line.begin(),line.end());
		cout<<line<<"\n";
		while(next_permutation(line.begin(),line.end()))
		{
			cout<<line<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}
