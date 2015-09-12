#include <iostream>

using namespace std;

int main()
{
	int P,C,H,W;
	while(cin>>P>>C>>H>>W)
	{
		int hotel[H][W];
		int money[H];
		for(int i=0 ; i<H ; i++)
		{
			cin>>money[i];
			for(int j=0 ; j<W ; j++)
			{
				cin>>hotel[i][j];
			}
		}
		int ans=2*C;
		for(int i=0 ; i<H ; i++)
		{
			for(int j=0 ; j<W ; j++)
			{
				if(hotel[i][j]>=P && money[i]*P<=C)
				{
					if(money[i]*P < ans)
						ans=money[i]*P;
				}
			}
		}
		if(ans>C)cout<<"stay home\n";
		else cout<<ans<<"\n";

	}
	return 0;
}