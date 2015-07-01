#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,t=0;
	while(cin>>n)
	{
		
		t++;
		cout<<"Case #"<<t<<": ";
		int data[n],sum[20000];
		for(int i=0;i<n;i++)
			cin>>data[i];
		bool flag=0;	
		for(int i=0;i<n;i++)
		{
			if(data[i]<1)
			{
				flag=1;
				break;
			}
			if(data[i]>data[i+1] &&i+1<n)
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			int move=0;
			for(int i=0;i<n;i++)
			{
				for(int j=i;j<n;j++)
				{
					sum[move++]=data[i]+data[j];
				}
			}
		
			sort(sum,sum+move);
		
			for(int i=0;i<move-1;i++)
			{
				if(sum[i]==sum[i+1])
				{
					flag=1;
					break;
				}
			}
		}
		if(flag)
		{
			cout<<"It is not a B2-Sequence.\n";
		}
		else
		{
			cout<<"It is a B2-Sequence.\n";
		}
		cout<<'\n';
	}
	return 0;
}
