#include <iostream>  
#include<stack>
#include<cstring>
#include<stdio.h>
#include<cstdlib>
using namespace std;  
		  
int main (int argc, char *argv[])  
{  

	char s[10000],a;
	while(cin>>s)
	{
		a=getchar();
	    int b=strlen(s);
	  	for(int i=b-1;i>=0;i--)
			cout<<s[i];
		cout<<a;	  
	}	      
return 0;  
}  
