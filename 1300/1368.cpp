#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const char seq[]={'A','C','G','T'};
int main()
{
	int num;
	cin>>num;
	for(int t=0 ; t<num ; t++)
	{
		int r,n;
		cin>>r>>n;
		char data;
		int table[n][4];                     //A0 C1 G2 T3
		memset(table,0,sizeof(table));
		for(int i=0 ; i<r ; i++)
		{
			for(int j=0 ; j<n ; j++)
			{
				cin>>data;
				if(data=='A')
					table[j][0]++;
				else if(data=='C')
					table[j][1]++;
				else if(data=='G')
					table[j][2]++;
				else if(data=='T')
					table[j][3]++;
			}
		}
		int max,ans,sum=0;
		for(int i=0;i<n;i++)
		{
			max=0;
			for(int j=0;j<4;j++)
			{
				sum+=table[i][j];
				if(table[i][j]>max)
				{
					max=table[i][j];
					ans=j;
				}
			}
			sum-=max;
			cout<<seq[ans];
		}cout<<'\n';
		cout<<sum<<'\n';
	}
	return 0;
}
