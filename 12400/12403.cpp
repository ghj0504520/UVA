#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int num,ans=0;
	string cmd;
	cin>>num;
	while(num--)
	{
		cin>>cmd;
		if(cmd=="donate")
		{
			cin>>num;
			ans+=num;
		}
		else if(cmd=="report")
		{
			cout<<ans<<"\n";
		}
	}
	return 0;
}