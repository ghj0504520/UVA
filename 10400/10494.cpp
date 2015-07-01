#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	char q[10000],op;
	long long div;
	while(scanf("%s %c %lld",q,&op,&div)!=EOF)
	{
		long long r=0,pos=0;
		int ans[10000]={0};
		int len=strlen(q);
		for(int i=0;i<len;i++)
		{
			r=r*10+(q[i]-'0');
			ans[pos++]=r/div;
			r%=div;
		}
		if(op=='%')
		{
			cout<<r<<'\n';
		}
		else if(op=='/')
		{
			int l=0,flag=0;
			for(int i=0;i<len;i++)
			{
				if(ans[i])
				{
					l=i;
					flag++;
					break;
				}
			}
			if(!flag)
			{
				cout<<0;
			}
			else
			{
				for(int i=l;i<len;i++)
				{
					cout<<ans[i];
				}
			}
			cout<<'\n';
		}
	}
	return 0;
}
