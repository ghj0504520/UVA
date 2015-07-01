#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int square[200000];
	memset(square,0,sizeof(square));
	for(int i=0;i*i<100000;i++)
	{
		square[i*i]=1;
	}
	int s,d;
	while(cin>>s>>d)
	{
		if(!s&&!d)
		{
			break;
		}
		int sum=0;
		for(int i=s;i<=d;i++)
			if(square[i])
				sum++;
		cout<<sum<<"\n";
	}
	return 0;
}
