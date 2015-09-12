#include <iostream>

using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		cout<<(int)(n/3)*(int)(m/3)<<"\n";
	}
	return 0;
}