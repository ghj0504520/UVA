#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int m ,n ,t=0;
	while(cin>>m>>n)
	{
		if(m==n && !m) break;
		cout<<"Region "<<++t<<'\n';

		int  part[m*n];
		for(int i=0 ; i<m*n ; i++)
			cin>>part[i];
		sort(part,part+m*n);
		
		int v,sum=0;
		cin>>v;
		for(int i=0 ; i<m*n ; i++)
		{	
			double h;
			sum+=part[i];
			h=((double)v+sum*100)/(i+1)/100;
			
			if(h<part[i+1])
			{
				printf("Water level is %.2lf meters.\n",h);
				printf("%.2lf percent of the region is under water.\n\n",((double)i+1)*100/(m*n));
				break;
			}
		}
	}
	return 0;
}
