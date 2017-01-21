#include <iostream>
#include <algorithm>
#include <vector>

#define INF 1e9

using namespace std;

int main()
{
	int V,E,Q,t=0;

	while(cin>>V>>E>>Q)
	{
		if(!V&&!E&&!Q)break;

		vector< vector<int> >dp(V);

		for(int i=0 ; i<V ; i++)
		{
			dp[i].resize(V,INF);
			dp[i][i]=0;
		}

		for(int i=0 ; i<E ; i++)
		{
			int s,d,w;
			cin>>s>>d>>w;
			dp[s-1][d-1]=w;
			dp[d-1][s-1]=w;
		}

		for (int k=0 ; k<V ; k++)
		{
			for (int i=0 ; i<V ; i++)
			{
				for (int j=0 ; j<V ; j++)
				{
					if(dp[i][j]>max(dp[i][k],dp[k][j]))
					{
						dp[i][j]=max(dp[i][k],dp[k][j]);
					}
				}
			}
		}

		if(t)cout<<"\n";
		cout<<"Case #"<<++t<<"\n";
		for(int i=0 ; i<Q ; i++)
		{
			int s,d;
			cin>>s>>d;
			if(dp[s-1][d-1]!=INF)
			{
				cout<<dp[s-1][d-1]<<"\n";
			}
			else
			{
				cout<<"no path\n";
			}
		}
	}

	return 0;
}
