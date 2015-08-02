#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	string num;
	while(cin>>num)
	{
		if(num=="0")break;
		long long ans=0,len=num.size(),L=len;
		for(int i=len ; i>0 ; i--)
		{
			ans+=(num[L-i]-'0')*(pow(2,i)-1);
		}
		cout<<ans<<"\n";
	}
	return 0;
}