#include <iostream>

using namespace std;

int H,K;
int tree[(1<<20)+10];
void buildTree(int index,int level)
{
	if(level > H)return;
	cin>>tree[index];
	//cout<<tree[index]<<" ";
	buildTree(index*2+1 , level+1);
	buildTree(index*2+2 , level+1);
}

int solve()
{
	int t = (1<<(H+1))-1;
	int dp[t][K+1];
	for (int i = 1; i <= K; i++)
	{
		for (int j = t-1; j >= 0; j--)
		{
			if(i==1)
			{
				dp[j][i] = tree[j];
			}
			else
			{
				int l = j*2+1;
				int r = j*2+2;

				dp[j][i] = dp[j][i-1];

				if (l > t || r > t) 
					continue;

				for (int x = 1; x < i; x++)
					dp[j][i] = max(dp[j][i], dp[l][x] + dp[r][i-x]);
			}
		}
	}
	return dp[0][K];
}

int main()
{
	while(cin>>H)
	{
		if(H==-1)break;
		cin>>K;
		buildTree(0,0);
		cout<<solve()<<"\n";
	}
	return 0;
}