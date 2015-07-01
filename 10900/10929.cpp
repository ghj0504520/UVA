#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int main()
{
	char a[20000];
	
	while(cin>>a )
	{
		if(a[0]=='0'&&a[1]=='\0')break;
		int sum =strlen(a);
		int odd=0, even =0;
		for(int i=0;i<sum;i++)
		{
			i%2==0? even=even+(int)(a[i]-48) : odd=odd+(int)(a[i]-48);
		   
		}if(odd>even)
		{
			int swap =even;
			even=odd;
			odd=swap;
		}
		if((even-odd)%11==0)
		{
			for(int i=0;i<sum ;i++)
				cout<<a[i];
			printf(" is a multiple of 11.\n");
		}else if((even-odd)%11!=0)
		{
			for(int i=0;i<sum ;i++)
				cout<<a[i];
			printf(" is not a multiple of 11.\n");
		}
		
		
	}
}
