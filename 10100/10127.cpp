#include <iostream>

using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		long long sum=1,ans=0;
		while(1)
		{
			ans++;
			if(!(sum%n))break;
			
			else sum=sum*10+1;
			
			sum%=n;  //figure out Time Limit Exceed
		}
		cout<<ans<<'\n';
	}
	return 0;
}
