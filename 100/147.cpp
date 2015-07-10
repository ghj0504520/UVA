#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int coin_table[11]={1,2,4,10,20,40,100,200,400,1000,2000};
long long coin_change[6010];

void dp_init()
{
	memset(coin_change,0,sizeof(coin_change));
	coin_change[0]=1;
	for(int i=0 ; i<11 ; i++)
	{
		for(int c=coin_table[i] ; c<6010 ; c++)
		{
			coin_change[c]=coin_change[c]+coin_change[c-coin_table[i]];
		}
	}
}
int main()
{
	dp_init();
	double input;
	while(cin>>input)
	{
		if(input==0.00)break;

		int ans=input*100/5+0.5f;
		printf("%6.2f%17lld\n",input,coin_change[ans]);
	}
	return 0;
}
