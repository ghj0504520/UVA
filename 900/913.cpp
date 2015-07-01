#include <iostream>

using namespace std;

int main()
{
	long long q;
	while(cin>>q)
	{
		long long num=(1+q)/2*((q-1)/2+1);
		long long last=1+(num-1)*2;
		
		last=last+last-2+last-4;
		cout<<last<<'\n';
	}
	return 0;
}
