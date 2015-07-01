#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char line[10000];
	while(fgets(line,9999,stdin))
	{
		int len=strlen(line);
		for(int i=0;i<len;i++)
		{
			line[i]=line[i]-7;
			
		}
		line[len-1]='\0';
		printf("%s\n",line);
	}
	return 0;
}
