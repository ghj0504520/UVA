#include <iostream>
#include <cstdio>
using namespace std;

int dp[30][30], op[30][30];
void backtrack(string a,int ia,string b,int ib)
{
	if(!ia&&!ib)return;

	if(op[ia][ib]==1)
	{
		backtrack(a, ia-1, b, ib);
		printf("D%c%02d", a[ia-1], ib+1);
	}else if(op[ia][ib]==2)
	{
		backtrack(a, ia, b, ib-1);
		printf("I%c%02d", b[ib-1], ib);
	}else if(op[ia][ib]==3)
	{
		backtrack(a, ia-1, b, ib-1);
		printf("C%c%02d", b[ib-1], ib);
	}else
	{
		backtrack(a, ia-1, b, ib-1);
	}
}

int main(int argc, char const *argv[])
{
	string in1,in2;
	while(cin>>in1)
	{
		if(in1=="#")break;

		cin>>in2;

		
		int l1=in1.length(),l2=in2.length();

		for (int i = 0; i <= l1; ++i)
		{
			for (int j = 0; j <= l2; ++j)
			{
				dp[i][j]=10000;
				op[i][j]=0;
			}
		}

		for (int i = 0; i <= l1; ++i)
		{
			dp[i][0]=i;
			op[i][0]=1;
		}

		for (int j = 0; j <= l2; ++j)
		{
			dp[0][j]=j;
			op[0][j]=2;
		}

		for (int i = 1; i <= l1; ++i)
		{
			for (int j = 1; j <= l2; ++j)
			{
				if(in1[i-1] !=in2[j-1])
				{
					dp[i][j]=dp[i-1][j-1]+1;
					op[i][j]=3;
				}else
				{
					dp[i][j]=dp[i-1][j-1];
				}

				if(dp[i][j]>dp[i-1][j]+1)
				{
					dp[i][j]=dp[i-1][j]+1;
					op[i][j]=1;
				}

				if(dp[i][j]>dp[i][j-1]+1)
				{
					dp[i][j]=dp[i][j-1]+1;
					op[i][j]=2;
				}
			}
		}

		backtrack(in1,l1,in2,l2);
		cout<<"E\n";
	}	
	return 0;
}