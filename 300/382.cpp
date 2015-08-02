#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int num;
	cout<<"PERFECTION OUTPUT\n";
	while(cin>>num,num)
	{
		int square=sqrt(num);
		int ans=0;
		for(int i=1 ; i<=square ;i++)
		{
			if(num%i==0)
			{
				int remain=num/i;
				if(i!=remain)
				{
					ans+=remain;
				}
				ans+=i;
			}
		}
		ans-=num;
		cout<<setw(5)<<num<<"  ";
		if(ans==num)
		{
			cout<<"PERFECT\n";
		}
		else if(ans>num)
		{
			cout<<"ABUNDANT\n";
		}
		else if(ans<num)
		{
			cout<<"DEFICIENT\n";
		}
	}
	cout<<"END OF OUTPUT\n";
	return 0;
}