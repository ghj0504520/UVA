#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		long long s[4];
		bool jump=0;
		for (int i = 0; i < 4; ++i)
		{
			cin>>s[i];
			if(!s[i])
			{
				cout<<"banana\n";
				jump=1;
			}
		}
		if(jump)continue;

		sort(s,s+4);
		
		if(s[0]==s[3])
			cout<<"square\n";
		else if(s[0]==s[1]&&s[2]==s[3])
			cout<<"rectangle\n";
		else if(s[3]<=s[0]+s[1]+s[2])
			cout<<"quadrangle\n";
		else
			cout<<"banana\n";
	}
	return 0;
}