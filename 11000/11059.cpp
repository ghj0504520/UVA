#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long int num,t=0;
	while(cin>>num)
	{
		cout<<"Case #"<<++t<<": ";
		long long int seq[num];
		for(int i=0 ; i<num ; i++)
		{
			cin>>seq[i];
		}	
		long long int sum,ans=0;
		
		for(int i=0 ; i<num ; i++)
		{
			sum=seq[i];
			ans=max(sum,ans);
			for(int j=i+1;j<num;j++)
			{
				sum*=seq[j];
				ans=max(sum,ans);
			}
		}
		if(!(ans>0))cout<<"The maximum product is 0.\n\n";
		else cout<<"The maximum product is "<<ans<<".\n\n";
		
	}
	return 0;
}
