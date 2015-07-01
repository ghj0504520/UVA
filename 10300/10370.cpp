#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int main()
{
	int a;
	while(cin>>a)
	{
		for(int i=0;i<a;i++)
		{
			int sum ;
			cin>>sum;
			int da[sum],s=0;
			for(int i=0;i<sum;i++)
			{
				cin>>da[i];
				s+=da[i];
			}int p=0;
			double avg=s/sum , rate;
			for(int i=0;i<sum;i++)
			{
				if(da[i]>avg)
					p++;
			}rate=(double)p/sum;
			rate=(double)rate*100;
			printf("%.3lf%%\n", rate);
			
		}
		
	}
}
