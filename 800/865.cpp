#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
	int num;
	cin>>num;
	getchar();
	getchar();
	for(int t=0;t<num;t++)
	{
		if(t!=0)cout<<'\n';
		char pre[2000],cur[2000];
		cin.getline(pre,200);
		cin.getline(cur,200);
		int len_pre=strlen(pre),len_cur=strlen(cur);
		cout<<cur<<'\n'<<pre<<'\n';
		for(int i=0;i<len_pre||i<len_cur;i++)
		{
			if(i>=len_pre)
				pre[i]=' ';
			if(i>=len_cur)
				cur[i]=' ';
		}
		char table[128];
		for(int i=0;i<128;i++)
			table[i]='\0';
		for(int i=0;i<len_pre;i++)
		{
			table[(int)pre[i]]=cur[i];
		}
		char in[200];
		while(cin.getline(in,200))
		{
			if(in[0]=='\0')break;
			int len_in=strlen(in);
			for(int i=0;i<len_in;i++)
			{
				if(table[(int)in[i]]!='\0')
					cout<<table[(int)in[i]];
				else 
					cout<<in[i];
			}cout<<'\n';
		}
		
		
	}
	return 0;
}
