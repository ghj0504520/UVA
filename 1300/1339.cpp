#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	string oldw,neww;
	int oldt[26],newt[26];
	while(cin>>oldw>>neww)
	{
		memset(oldt,0,sizeof(oldt));
		memset(newt,0,sizeof(newt));
		int l1=oldw.size(),l2=neww.size();
		for(int i=0;i<l1;i++)
		{
			oldt[(int)oldw[i]-'A']++;
		}
		for(int i=0;i<l2;i++)
		{
			newt[(int)neww[i]-'A']++;
		}
		sort(oldt,oldt+26);
		sort(newt,newt+26);
		bool check=1;
		for(int i=0;i<26;i++)
		{
			if(oldt[i]!=newt[i])
			{
				check=0;
				break;
			}
		}
		check ?cout<<"YES\n":cout<<"NO\n";
	}
	return 0;
}
