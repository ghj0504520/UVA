#include <iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>

using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
			if(n==0&&m==0)break;
			int dragon[n],ride[m];
			for(int i=0;i<n;i++)
				cin>>dragon[i];
			for(int j=0;j<m;j++)
				cin>>ride[j];
			sort(dragon,dragon+n);
			sort(ride,ride+m);
			int coast=0,k=0;
			for(int i=0;i<m;i++)
			{
				
				if(ride[i]>=dragon[k])
				{
						coast+=ride[i];
						k++;
						if(k==n)break;
				}
				
		
			}
			k<n?cout<<"Loowater is doomed!\n":cout<<coast<<'\n';
	};
	
	
	return 0;
}

