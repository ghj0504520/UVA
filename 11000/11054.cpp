#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
	int num;
	while(cin>>num)
	{
		if(!num)
			break;
		int data[num];
		for(int i=0;i<num;i++)
			scanf("%d",&data[i]);
		
		long long sum=0;
		for(int i=0;i<num;i++)               //greedy
		{
			sum+=abs(data[i]);
			data[i+1]+=data[i];
		}cout<<sum<<'\n';
	}
	return 0;
}
