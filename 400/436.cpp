#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int V,t=0;
	while(cin>>V,V)
	{
		string v;
		int cnt=0;
		map<string,int> table;
		for(int i=0 ; i<V ; i++)
		{
			cin>>v;
			table[v]=cnt++;
		}


		vector< vector<double> >dp(V);
		for(int i=0 ; i<V ; i++)
		{
			dp[i].resize(V,1.0);
			dp[i][i]=0;
		}


		int E;
		cin>>E;
		for(int i=0 ; i<E ; i++)
		{
			string s,d;
			double w;
			cin>>s>>w>>d;
			dp[ table[s] ][ table[d] ]=w;
		}

		for (int k=0 ; k<V ; k++)
		{
			for (int i=0 ; i<V ; i++)
			{
				for (int j=0 ; j<V ; j++)
				{
					if(dp[i][j]<dp[i][k]*dp[k][j])
					{
						dp[i][j]=dp[i][k]*dp[k][j];
					}
				}
			}
		}

		cout<<"Case "<<++t<<": ";
		bool flag=0;
		for(int i=0 ; i<V ; i++)
		{
			if(dp[i][i]>1.0)
			{
				flag=1;
				break;
			}
		}
		cout<<(flag? "Yes\n":"No\n");
	}
}