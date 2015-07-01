#include <iostream>

using namespace std;

int main()
{
	int num;
	while(cin>>num,num)
	{
		cout<<num*(num+1)*(2*num+1)/6<<'\n';
	}
	return 0;
}
