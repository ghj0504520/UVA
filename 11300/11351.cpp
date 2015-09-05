#include <iostream>

using namespace std;

int main()
{
	int num;
	cin>>num;
	for(int i=0 ; i<num ; i++)
	{
		int n,m;
		cin>>n>>m;
		int remain=0;
		for(int k=2; k<=n; k++)
		{
			remain=(remain+m)%k;
		}
		cout<<"Case "<<i+1<<": "<<remain+1<<"\n";
	}
	return 0;
}