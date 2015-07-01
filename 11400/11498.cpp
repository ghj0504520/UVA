#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int num;
	while(cin>>num,num)
	{
		int d_x,d_y;
		cin>>d_x>>d_y;
		for(int i=0;i<num;i++)
		{
			int x,y;
			cin>>x>>y;
			if(x==d_x || y==d_y)
			{
				cout<<"divisa\n";				
				continue;
			}
			if(y>d_y)
			{
				cout<<'N';
			}
			else if(y<d_y)
			{
				cout<<'S';
			}
			if(x>d_x)
			{
				cout<<'E';
			}
			else if(x<d_x)
			{
				cout<<'O';
			}
			cout<<"\n";
		}
	}
	return 0;
}
