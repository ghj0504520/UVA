#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	for (int t = 0;  t<T ; ++t)
	{
		int income;
		cin>>income;
		double tax=0;
		if(income>180000)
		{
			income-=180000;
			if(income>300000)
			{
				income-=300000;
				tax+=300000*0.1;
				if(income>400000)
				{
					income-=400000;
					tax+=400000*0.15;
					if(income>300000)
					{
						income-=300000;
						tax+=300000*0.2;
						tax+=income*0.25;
					}
					else	tax+=income*0.2;
				}
				else	tax+=income*0.15;
			}
			else	tax+=income*0.1;
			if(tax<2000)tax=2000;
		}
		cout<<"Case "<<t+1<<": "<<(int)ceil(tax)<<"\n";
	}
	return 0;
}