#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int num,t=0;
	while(cin>>num,num)
	{
		cout<<"Game "<<++t<<":\n";
		int ans[num],table[10]={0};
		for(int i=0 ; i<num ; i++)
			cin>>ans[i];
		for(int i=0 ; i<num ; i++)
		{
			table[ans[i]]++;
		}


		int query[num];
		while(1)
		{
			for(int i=0 ; i<num ; i++)
				cin>>query[i];
			
			bool check=0;
			for(int i=0 ; i<num ; i++)
			{
				if(query[i])
				{
					check=1;
					break;
				}
			}if(!check)break;
			
			
			int yes=0,na=0,q_table[10]={0};
			for(int i=0 ; i<num ; i++)
			{
				if(ans[i]==query[i])
					yes++;
			}
						
			
			for(int i=0 ; i<num ; i++)
			{
				q_table[query[i]]++;
			}
			for(int i=0 ; i<10 ; i++)
			{
				na+=min(table[i],q_table[i]);
			}
			na-=yes;
			cout<<"    ("<<yes<<","<<na<<")\n";
		}
	}
	return 0;
}
