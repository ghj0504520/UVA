#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	char c,out;
	int ans=0;
	while((c=getchar())!=EOF)
	{
		if(c=='\n'||c=='!')cout<<"\n";
		else
		{
			if(c>='0'&&c<='9')ans+=c-'0';
			else
			{
				if(c=='b')out=' '; 
				else	out=c;
				for(int i=0 ; i<ans ; i++)cout<<out;
				ans=0;
			}
		}
	}
	return 0;
}