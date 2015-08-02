#include <iostream>

using namespace std;

int main()
{
	int num;
	while(cin>>num)
	{
		int data[1000],ans=0;
		for(int i=0 ; i<num ; i++)	cin>>data[i];

		for(int i =num-1; i >=0 ;i --)
		{
			for(int j =0; j < i; j++)
			{
				if(data[j] > data[j+1] )
				{
					int tmp=data[j];
					data[j]=data[j+1];
					data[j+1]=tmp;
					ans++;
				}
			}
		}
		cout<<"Minimum exchange operations : "<<ans<<"\n";
	}
	return 0;
}