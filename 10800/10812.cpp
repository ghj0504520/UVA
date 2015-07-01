#include <iostream>

using namespace std;

int main()
{
	int num;
	while(cin>>num)
	{
		for(int i=0;i<num;i++)
		{
			int x,y;
			cin>>x>>y;
			if((x<y)||((x+y)%2)||((x-y)%2))
			{
				cout<<"impossible\n";
			}
			else
			{
				cout<<(x+y)/2<<" "<<(x-y)/2<<"\n";
			}
		}
	}
	return 0;
}
