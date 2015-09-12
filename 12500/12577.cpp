#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);

	string cmd;
	int t=0;
	while(cin>>cmd)
	{
		if(cmd=="*")
		{
			break;
		}
		else
		{
			++t;
			cout<<"Case "<<t<<": Hajj-e-";
			if(cmd=="Hajj")
			{
				cout<<"Akbar\n";
			}
			else if(cmd=="Umrah")
			{
				cout<<"Asghar\n";
			}
		}
	}

	return 0;
}