#include <iostream>

using namespace std;
int MILE(int SEC)
{
	SEC++;
	int ans1=0;
	while(SEC>=30)
	{
		ans1++;
		SEC-=30;
	}
	if(SEC>0)ans1++;
	return ans1*10;
}
int JUICE(int SEC)
{
	SEC++;
	int ans1=0;
	while(SEC>=60)
	{
		ans1++;
		SEC-=60;
	}
	if(SEC>0)ans1++;
	return ans1*15;
}
int main()
{
	int T;
	cin>>T;
	for(int i=0 ; i<T ; i++)
	{
		int num;
		cin>>num;
		int sec[num];
		for(int j=0 ; j<num ; j++)cin>>sec[j];
		int mile=0,juice=0;
		for(int k=0 ; k<num ; k++)
		{
			int m,j;
			m=MILE(sec[k]);
			j=JUICE(sec[k]);
			mile+=m;
			juice+=j;	
		}
		cout<<"Case "<<i+1<<": ";
		if(mile<juice)
			cout<<"Mile "<<mile;
		else if(mile>juice)
			cout<<"Juice "<<juice;
		else
			cout<<"Mile Juice "<<mile;
		cout<<"\n";
	}
	return 0;
}