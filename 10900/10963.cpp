#include <iostream>

using namespace std;

int main()
{
	int num;
	cin>>num;
	for(int t=0;t<num;t++)
	{
		if(t)cout<<'\n';
		int c;
		cin>>c;
		int n,s,diff;
		cin>>n>>s;
		diff=n-s;
		bool check=1;
		for(int i=1;i<c;i++)
		{
			cin>>n>>s;
			if(n-s!=diff)
			{
				check=0;
			}
		}
		check?cout<<"yes":cout<<"no";
		cout<<"\n";
	}
	return 0;
}
