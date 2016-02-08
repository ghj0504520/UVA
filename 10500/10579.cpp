#include <iostream>

using namespace std;

int digit[10000][2000]={0};

void FIB()
{
	digit[0][0]=0;
	digit[1][0]=1;
	for(int i=2 ; i<10000 ; i++)
	{
		for(int j=0 ; j<2000 ; j++)
			digit[i][j]=digit[i-1][j]+digit[i-2][j];
		for(int j=1 ; j<2000 ; j++)
		{
			if(digit[i][j-1]>9)
			{
				digit[i][j]+=digit[i][j-1]/10;
				digit[i][j-1]%=10;
			}
		}
	}
}

void print(int num)
{
	bool p=0;
	for(int i=2000-1 ; i>=0 ; i--)
	{
		if(digit[num][i]&&!p)p=1;

		if(p)cout<<digit[num][i];
	}cout<<"\n";
}

int main()
{
	FIB();
	int q;
	while(cin>>q)
	{
		print(q);
	}
	return 0;
}