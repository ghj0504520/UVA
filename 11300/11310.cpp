#include <iostream>

using namespace std;

int main()
{
	long long rec[50]={0},flow[50]={0};
	rec[0]=0;
	rec[1]=1;
	rec[2]=5;
	flow[0]=0;
	flow[1]=1;
	flow[2]=2;
	for(int i=3 ; i<50 ; i++)
	{
		rec[i]=rec[i-1] + 2*rec[i-2] +2*flow[i-1];
		flow[i]=rec[i-1] +rec[i-2];
	}
	int n;
	cin>>n;
	while(n--)
	{
		int q;
		cin>>q;
		cout<<rec[q]<<'\n';
	}
	return 0;
}
