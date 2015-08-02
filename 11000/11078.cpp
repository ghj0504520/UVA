#include <iostream>

using namespace std;

int main()
{
	int run;
	cin>>run;
	for(int t=0 ; t<run ; t++)
	{
		int num,cur,Max,Ans=-1000000;
		cin>>num;
		cin>>Max;
		for(int i=1 ; i<num; i++ )
		{
			cin>>cur;
			Ans= Ans < Max-cur ? Max-cur : Ans;
			Max= cur>Max ? cur:Max; 
		}
		cout<<Ans<<"\n";

	}
	return 0;
}