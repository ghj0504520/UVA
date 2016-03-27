#include <iostream>

#define M 5000000

using namespace std;

bool P[M+10]={0};
int DEP[M+10]={0};
void seize()
{
	P[0]=P[1]=1;
	DEP[0]=0;
	DEP[1]=1;
	for(int i=2 ; i<=M ; i++)
	{
		if(!P[i])
		{
			DEP[i]+=i;
			for (int j=i+i ; j<=M ; j+=i)
			{
				P[j]=1;
				DEP[j]+=i;
			}
		}
	}
}

int main()
{
	seize();
	int a,b;
	while(cin>>a,a)
	{
		cin>>b;
		int sum=0;
		for(int i=a ; i<=b ; i++)
		{
			if(!P[ DEP[i] ])
				sum++;
		}
		cout<<sum<<"\n";
	}
	return 0;
}