#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int num;
	while(cin>>num,num)
	{
		int course;
		vector<int> comb;
		map< vector<int>,int >table;
		for(int i=0 ; i<num ;i++)
		{
			comb.clear();
			for(int j=0 ; j<5 ; j++ )
			{
				cin>>course;
				comb.push_back(course);
			}
			sort(comb.begin(),comb.end());
			table[comb]++;
		}
		int M=-1;
		map< vector<int>,int >::iterator it;
		for(it=table.begin();it!=table.end();it++)
		{
			if(it->second > M)M=it->second;
		}
		int ans=0;
		for(it=table.begin();it!=table.end();it++)
		{
			if(it->second==M)ans+=it->second;
		}
		cout<<ans<<"\n";
	}
	return 0;
}