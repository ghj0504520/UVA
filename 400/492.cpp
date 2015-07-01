#include <iostream>  
#include<stack>
#include<cstring>
#include<stdio.h>
#include<cstdlib>
using namespace std;  
bool vowel(char k)
{
	if(k=='a'||k=='e'||k=='i'||k=='o'||k=='u'||k=='A'||k=='E'||k=='I'||k=='O'||k=='U')
 		return 1;
 	return 0;	  
}
bool alpha(char p)
{
	if(p>=65&&p<=90)
		return 1;
	else if(p>=97&&p<=122)
		return 1;
	return 0;

}
int main (int argc, char *argv[])  
{  
//freopen("in", "r", stdin);    
//freopen("out", "w", stdout);  
	char s;
	while(1)
	{	//bool j=0;
		int n=scanf("%c",&s);
		if(n!=1)
			break;
		if(vowel(s)==1)
		{
		   cout<<s;
		   while(cin.get(s))
		   {
		   		if(alpha(s)==1)
		   			cout<<s;
		   		else if(alpha(s)==0) 		   			
		   		{	
		   			break;
		   		}
		   }
		   cout<<"ay";
		   if(s!='\n')cout<<s;
		   
		}
		else if(vowel(s)==0)
		{
			if(alpha(s)==1)
			{ 
				char r=s;
				while(cin.get(s))
				{
				 	if(alpha(s)==1)
		   				cout<<s;
					else if(alpha(s)==0) 		   			
		   		    {	
		   				break;
		   			}
				}cout<<r<<"ay";
				if(s!='\n')cout<<s;
		   		
			
			}
			else if(alpha(s)==0)
				putchar(s);
			
		
		
		}
		//cout<<'\n';   
	}	   
return 0;  
}  
