#include<iostream>
#include<cstdio>
#include<string.h>
#include<cstdlib>
using namespace std;
int main()
{
	int num;
	while(cin>>num)
	{
		bool jully=0;
		int da[num];
		for(int i=0;i<num;i++)
			cin>>da[i];
		bool judge[num];
		for(int i=0;i<num;i++)
		{
			judge[i]=0;
		}
		for(int i=0;i<num-1;i++)
		{
			judge[abs(da[i]-da[i+1])]=1;
		}
		for(int i=1;i<num;i++)
		{
			if(judge[i]==0)
			{
				jully=1;
				break;
			}
	     }
		jully==0? cout<<"Jolly\n": cout<<"Not jolly\n";
	}
		
}
