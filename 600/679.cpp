#include <iostream>

using namespace std;

int main()
{
	int num;
	while(cin>>num)
	{
		if(num==-1)break;

		int deep,cnt;
		for(int t=0 ; t<num ;t++)
		{
			cin>>deep>>cnt;
			int k=1;
			for(int d=0 ; d<deep-1 ;d++)
			{
				if(cnt%2)
				{
					k=k*2;
					cnt=(cnt+1)/2;
				}
				else
				{
					k=k*2+1;
					cnt=cnt/2;
				}

			}
			cout<<k<<"\n";
		}
	}
	return 0;
}