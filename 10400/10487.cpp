#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>

#define MAX 1000

using namespace std;

int table[MAX+10];

int main()
{
	ios::sync_with_stdio(0);
	int num,t=0;
	while(cin>>num,num)
	{
		memset(table,0,sizeof(table));
		set<int>table1;
		vector<int>table2;

		for(int i=0 ; i<num ; i++)cin>>table[i];

		for(int i=0 ; i< num ; i++)
		{
			for(int j=i+1 ; j<num ; j++)
			{
				if(i!=j)
				{
					int cur=table[i]+table[j];
					if(!table1.count(cur))
					{
						table1.insert(cur);
						table2.push_back(cur);
					}
				}
			}
		}

		sort(table2.begin(),table2.end());

		int qnum;
		cin>>qnum;
		cout<<"Case "<<++t<<":\n";
		while(qnum--)
		{
			int query;
			cin>>query;
			vector<int>::iterator it=lower_bound(table2.begin(),table2.end(),query);
			int dis=it-table2.begin();
			if(dis-1>=0)
				dis = abs(table2[dis-1]-query)< abs(table2[dis]-query) ?dis-1:dis;
			cout<<"Closest sum to "<<query<<" is "<<table2[dis]<<".\n";
		}

	}
	return 0;
} 