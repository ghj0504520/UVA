#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
int primeTable[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int primeCnt[105];

void primeProcess(int check)
{
	int square=sqrt(check);
	for(int i=2 ; i<=square ; i++)
	{
		if(check%i==0 && binary_search(primeTable,primeTable+25,i))
		{
			while(check%i==0)
			{
				check/=i;
				primeCnt[i]++;
			}
		}
	}
	if(binary_search(primeTable,primeTable+25,check))
	{
		primeCnt[check]++;
	}
}
int main()
{
	int num;
	while(cin>>num,num)
	{
		cout<<setw(3)<<num<<"! =";
		memset(primeCnt,0,sizeof(primeCnt));

		int cur;
		for(int i=num ; i>0 ; i--)
		{
			primeProcess(i);
		}
		int blank=0;
		for(int i=0 ; i<105 ; i++)
		{
			if(primeCnt[i])
			{
				if(blank++==15){blank=0;cout<<"\n      ";}
				cout<<setw(3)<<primeCnt[i];
			}
		}
		cout<<"\n";
	}
	return 0;
}