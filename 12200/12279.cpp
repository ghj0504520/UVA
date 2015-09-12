#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int num,t=0;
	while(cin>>num,num)
	{
		cout<<"Case "<<++t<<": ";
		int data;
		int p=0,z=0;
		for(int i=0 ; i<num ; i++)
		{
			cin>>data;
			!data ? z++ : p++;
		}
		cout<<p-z<<"\n";
	}
	return 0;
}