#include <iostream>

using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string q;
		cin>>q;
		int len=q.size();
		if(q=="1"||q=="4"||q=="78")cout<<"+\n";

		else if(q[len-2]=='3'&&q[len-1]=='5')cout<<"-\n";

		else if(q[0]=='9'&&q[len-1]=='4')cout<<"*\n";

		else if(q[0]=='1'&&q[1]=='9'&&q[2]=='0')cout<<"?\n";
	}
	return 0;
}