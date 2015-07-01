#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
using namespace std;
int main()
{
	char a;
	bool b=0;
	while(scanf("%c",&a)!=EOF)
	{
	
		if(a=='\"' && b==0)
		{
				cout<<"``";
				b=1;
		}else if(a=='\"' && b==1)
		{
				cout<<"\'\'";
				b=0; 
		}else 
			cout<<a;
	}

}
