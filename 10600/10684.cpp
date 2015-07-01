#include<iostream>
using namespace std;
int main()
{

	int read;
	while(cin>>read)
	{
		if(read==0)
			break;
		int data[read];

		for(int i=0;i<read;i++)
			cin>>data[i];
		bool judge=0;
		for(int i=0;i<read;i++)
		{
			if(data[i]>0)
			{
				judge=1;
				break;
			}
		}
		if(judge==0)
		{
			cout<<"Losing streak.\n";
		}else if(judge==1)
		{

			int sum=0,swap=0;
			for(int i=0;i<read;i++)
			{

				swap+=data[i];
				if(swap<=0)
					swap=0;
				if(swap>sum)
					sum=swap;

			}cout<<"The maximum winning streak is "<<sum<<".\n";
		}
	}
}
