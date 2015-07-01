#include <iostream>
#include <vector>
using namespace std;

vector <int>table[1000010];
int main()
{
	ios::sync_with_stdio(0);
	int num,qnum;
	while(cin>>num>>qnum)
	{
		for(int i=0 ; i<1000010 ; i++)
			table[i].clear();
		
		for(int i=1 ; i<=num ; i++)
		{
			int n;
			cin>>n;
			table[n].push_back(i);
		}
		for(int i=0 ; i<qnum ; i++)
		{
			int q,pos;
			cin>>pos>>q;
			if(pos>table[q].size())
				cout<<"0\n";
			else
				cout<<table[q][pos-1]<<'\n';
		}
	}
	return 0;
}
