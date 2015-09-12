#include <iostream>

using namespace std;

int main()
{
	int num;
	cin>>num;
	while(num--)
	{
		int n;
		cin>>n;
		n=(((((n*567)/9)+7492)*235)/47)-498;
		n=n%100/10;
		n= n<0? n*-1 : n;
		cout<<n<<"\n";
	}
	return 0;
}