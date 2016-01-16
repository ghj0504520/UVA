#include <iostream>

#define M 1000000

using namespace std;
bool P[M+10]={0};
int PD[M+10]={0};

void seize()
{
	P[0]=1;
	P[1]=1;
	for(int i=2 ; i<=M ; i++)
		if(!P[i])
			for(int j=i+i ; j<=M ; j+=i)P[j]=1;
}

int sumdigit(int num)
{
	int sum=0;
	while(num)
	{
		sum+=num%10;
		num/=10;
	}return sum;
}

void solution()
{
	for(int i=1 ; i<=M ; i++)
	{
		if(!P[i] && !P[sumdigit(i)])PD[i]=1;
		PD[i]+=PD[i-1];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	seize();
	solution();
	int N;
	cin>>N;
	while(N--)
	{
		int a,b;
		cin>>a>>b;
		cout<<PD[b]-PD[a-1]<<"\n";
	}
	return 0;
}