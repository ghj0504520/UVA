#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

const char *mirror_table={"A   3  HIL JM O   2TUVWXY51SE Z  8 "};
const char output[4][50]={"not a palindrome.","a regular palindrome.","a mirrored string.","a mirrored palindrome."};

bool reverse(char in[],int len)
{
	for(int i=0 ; i<=len/2 ; i++)
	{
		if(in[i]!=in[len-1-i])
			return 0;
	}
	return 1;
}

bool mirror(char in[],int len)
{
	for(int i=0 ; i<=len/2 ; i++)
	{
		if(isalpha(in[i]))
		{
			if(mirror_table[in[i]-'A']!=in[len-1-i])
			{
				return 0;
			}
		}
		else
		{
			if(mirror_table[in[i]-'0'+25]!=in[len-1-i])
				return 0;
		}
	}
	return 1;
}

int main()
{
	char seq[10000];
	while(scanf("%s",seq)!=EOF)
	{
		int len=strlen(seq),m=0,r=0;
		if(reverse(seq,len))
		{
			r=1;
		}
		if(mirror(seq,len))
		{
			m=1;
		}
		cout<<seq<<" -- ";
		if(r==1)
		{
			if(m==1)
				cout<<"is "<<output[3];
			else if(m==0)
				cout<<"is "<<output[1];
		}
		else if(r==0)
		{
			if(m==1)
				cout<<"is "<<output[2];
			else if(m==0)
				cout<<"is "<<output[0];
		}
		cout<<"\n\n";
	}
	return 0;
}
