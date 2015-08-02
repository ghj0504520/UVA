#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int r;
	cin>>r;
	for (int t = 0; t < r; ++t)
	{
		int G[4];
		cin>>G[0]>>G[1]>>G[2]>>G[3];
		int T[3];
		cin>>T[0]>>T[1]>>T[2];
		sort(T,T+3);
		int sum=G[0]+G[1]+G[2]+G[3]+(T[2]+T[1])/2;
		cout<<"Case "<<t+1<<": ";
		if(sum>=90)
		{
			cout<<"A\n";
		}
		else if(sum>=80&&sum<90)
		{
			cout<<"B\n";
		}
		else if(sum>=70&&sum<80)
		{
			cout<<"C\n";
		}
		else if(sum>=60&&sum<70)
		{
			cout<<"D\n";
		}
		else if(sum<60)
		{
			cout<<"F\n";
		}
	}
	return 0;
}