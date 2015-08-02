#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int r;
	cin>>r;
	for (int t = 0; t < r; ++t)
	{
		int a,b;
		vector<string> A,B;
		set<string>table;
		cin>>a>>b;
		cin.ignore();
		string tmp;
		for(int i=0 ; i<a; i++)
		{
			getline(cin,tmp);
			A.push_back(tmp);
		}
		for(int i=0 ; i<b; i++)
		{
			getline(cin,tmp);
			B.push_back(tmp);
		}
		for(int i=0 ; i<A.size(); i++)
		{
			for(int j=0 ; j<B.size(); j++)
			{
				tmp=A[i]+B[j];
				if(!table.count(tmp))
					table.insert(tmp);
			}
		}
		cout<<"Case "<<t+1<<": "<<table.size()<<"\n";
	}
	return 0;
}