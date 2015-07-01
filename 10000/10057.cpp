#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int num;
	while(cin>>num)
	{
		int data[num];
		for(int i=0 ; i<num ; i++)
			cin>>data[i];
		sort(data,data+num);	
		
		if(num%2)
		{
			int mid=data[num/2],t=0;
			for(int i=0 ; i<num ; i++)
			{
				if(data[i]==mid)
					t++;
			}
			cout<<mid<<" "<<t<<" 1\n";
		}
		else
		{
			int mid1=data[num/2-1],mid2=data[(num+1)/2],t=0;
			for(int i=0;i<num;i++)
			{
				if(data[i]==mid1 || data[i]==mid2)
					t++;
			}
			cout<<mid1<<" "<<t<<" ";
			if(mid1==mid2)
			{
				cout<<"1\n";
			}
			else
			{
				int c=0;
				for(int i=mid1 ; i<=mid2 ; i++)
				{
					c++;
				}
				cout<<c<<"\n";
			}
		}
	}
}
