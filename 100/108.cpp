#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int num,mp[150][150];
	while(cin>>num)
	{
		memset(mp,0,sizeof(mp));
		for(int i=1 ; i<=num ; i++)
		{
			for(int j=1 ; j<=num ; j++)
			{
				int value;
				cin>>value;
				mp[i][j]=value+mp[i][j-1]+mp[i-1][j]-mp[i-1][j-1];					//figure out
				
			}
		}
		int max=0,tmp;
		for(int x1=1 ; x1<=num ; x1++)
		{
			for(int y1=1 ; y1<=num ; y1++)
			{
				for(int x2=x1 ; x2<=num ; x2++)
				{
					for(int y2=y1 ; y2<=num ; y2++)
					{
						tmp=mp[x2][y2]-mp[x1-1][y2]-mp[x2][y1-1]+mp[x1-1][y1-1];	//figure out
						if(tmp>max)max=tmp;
					}
				}
			}
		}
		cout<<max<<'\n';
	}
	return 0;
}
