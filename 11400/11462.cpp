#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	while(cin>>n,n)
	{
		int man[n];
		for(int i=0;i<n;i++)
			scanf("%d",&man[i]);
			
		sort(man,man+n);
		
		for(int i=0;i<n;i++)
		{
			if(i)printf(" ");
			printf("%d",man[i]);
		}
		printf("\n");
	}
	return 0;
}
