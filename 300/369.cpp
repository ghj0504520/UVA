#include <iostream>

using namespace std;

int main()
{
	int n,r;
	while(cin>>n>>r)
	{
		if(!n&&!r)break;

		int S=1,D=n,len= n-r > r ? r : n-r ;
		long double ans=1.0;
		for(int i=0 ; i<len ;i++)
		{
			ans*=D;
			ans/=S;
			D--;
			S++;
		}
		cout<<n<<" things taken "<<r<<" at a time is "<<(long long)ans<<" exactly.\n";
	}
	return 0;
}