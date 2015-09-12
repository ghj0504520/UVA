#include <iostream>

using namespace std;

int main()
{
	int num;
	cin>>num;
	for(int i=0 ; i<num ; i++)
	{
		cout<<"Case "<<i+1<<": ";
		int n;
		cin>>n;
		int M=-1;
		for(int j=0 ; j<n ; j++)
		{
			int cur;
			cin>>cur;
			M = cur>M? cur : M;
		}
		cout<<M<<"\n";
	}
	return 0;
}