#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct listnode
{
	string word;
	listnode *next;
};

void decode(listnode **ptr,int num)
{
	listnode *pre=NULL,*cur=*ptr;
	for(int i=0 ; i<num-1 ; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	cout<<cur->word;
	if(cur != *ptr)
	{
		pre->next = cur->next;
		cur->next = *ptr;
		*ptr = cur;
	}
}

void encode(listnode **ptr,string neword)
{
	listnode *newptr;
	newptr = new listnode;
	newptr->word = neword;
	newptr->next = NULL;
	
	newptr->next = *ptr;
	*ptr = newptr;
}

int main()
{
	char in;
	in=getchar();
	listnode *dict=NULL;
	while(1)
	{
		if(isdigit(in))
		{
			if(in=='0')break;
			
			else
			{
				int sum=0;
				while(isdigit(in))
				{
					sum=sum*10+in-'0';
					in=getchar();
				}
				
				decode(&dict,sum);
			}
		}
		else if(isalpha(in))
		{
			string neword="\0";
			while(isalpha(in))
			{
				neword+=in;
				in=getchar();
			}
			cout<<neword;
			
			encode(&dict,neword);
		}
		else
		{
			cout<<in;
			in=getchar();
		}
	}
}
