#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int s,f;

void simulate_kmp(char seq[],int len)
{
	if(len==1)
	{
		s=0;
		f=1;
		return ;
	}
	else
	{
		while(seq[f]!='\0')
		{
			if(seq[s]==seq[f])
			{
				s++;
				f++;
			}
			else
			{
				f++;
			}
		}
	}
	return ;
}
int main()
{
	int num;
	cin>>num;
	getchar();
	for(int t=0 ; t<num ; t++)
	{
		if(t)cout<<'\n';
		char seq[200];
		cin>>seq;
		int len=strlen(seq);
		s=0,f=1;
		simulate_kmp(seq,len);
		!(len%(f-s))?cout<<f-s:cout<<len;
		cout<<'\n';
	}
	return 0;
}
