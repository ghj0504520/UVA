#include <iostream>

using namespace std;

int main()
{
	int T,t=0;
	cin>>T;
	while(T--)
	{
		if(t++)cout<<"\n";
		int D;
		cin>>D;
		int digit[1000000*2]={0};

		for(int i=D-1 ; i>=0 ; i--)
		{
			int l,r;
			cin>>l>>r;
			digit[i]=l+r;
		}

		for(int i=1 ; i<1000000*2 ; i++)
		{
			if(digit[i-1]>9)
			{
				digit[i]+=digit[i-1]/10;
				digit[i-1]%=10;
			}
		}
		bool p=0;
		for(int i=D ; i>=0 ; i--)
		{
			if(!p&&digit[i])p=1;

			if(p)cout<<digit[i];
		}
		cout<<"\n";
	}
	return 0;
}