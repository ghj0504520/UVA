#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	char n1[150],n2[150];
	int num1[150],num2[150];
	while(cin>>n1>>n2)
	{
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		int l1=strlen(n1),l2=strlen(n2);
		for(int i=0;i<l1;i++)
			num1[i]=n1[i]-'0';
		for(int i=0;i<l2;i++)
			num2[i]=n2[i]-'0';
			
		int n1f=0,n2f=0,m=0,ans1=0,ans2=0;
		while(n1f<l1 &&n2f<l2)                      //n2 move
		{
			if(num1[n1f]+num2[n2f]<4)
			{
				n1f++;
				n2f++;
			}
			else if(num1[n1f]+num2[n2f]>=4)
			{
				n2f=0;
				m++;
				n1f=m;
			}
		}
		ans1= max(l1,m+l2);
		
		n1f=0,n2f=0,m=0;
		while(n1f<l1 &&n2f<l2)                      //n1 move
		{
			if(num1[n1f]+num2[n2f]<4)
			{
				n1f++;
				n2f++;
			}
			else if(num1[n1f]+num2[n2f]>=4)
			{
				n1f=0;
				m++;
				n2f=m;
			}
		}
		ans2= max(l2,m+l1);
		cout<<min(ans1,ans2)<<'\n';
	}
	return 0;
}
