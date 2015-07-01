#include<iostream>

using namespace std;

int main()
{
	int r;
	cin>>r;
	while(r--)
	{
		int num;
		cin>>num;
		int data[num];
		for(int i=0;i<num;i++)
			cin>>data[i];
			
		int t=0;
		for(int i=num-1;i>=0;i--)
		{
			for(int j=0;j<i;j++)
			{
				if(data[j]>data[j+1])
				{
					t++;
					int temp=data[j];
					data[j]=data[j+1];
					data[j+1]=temp;
				}
			}
		}
		cout<<"Optimal train swapping takes "<<t<<" swaps.\n";
	}
	return 0;
}
