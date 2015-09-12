#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int guess,high,low;
	string cmd;
	while(cin>>guess,guess)
	{
		high=20,low=0;
		cin.ignore();
		while(1)
		{
			getline(cin,cmd);
			if(cmd=="right on")break;

			else if(cmd=="too low" && guess>low)low=guess;
			else if(cmd=="too high" && guess<high)high=guess;
			cin>>guess;
			cin.ignore();
		}
		if(guess<high && guess>low)
			cout<<"Stan may be honest\n";
		else
			cout<<"Stan is dishonest\n";
	}
	return 0;
}