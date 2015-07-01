#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	int num;
	while(cin>>num,num)
	{
		char line[num];
		cin>>line;
		int ans=20000000,len=strlen(line),pos_d=-1,pos_r=-1;
		
		for(int i=0 ; i<len ; i++)
		{
			if(line[i]=='Z')
			{
				ans=0;
				break;
			}
			if(line[i]=='R')
			{
				pos_r=i;
			}
			if(line[i]=='D')
			{
				pos_d=i;
			}
			if(pos_d>=0&&pos_r>=0)
			ans=min(abs(pos_r-pos_d),ans);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
