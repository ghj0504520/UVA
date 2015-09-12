#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	string num;
	while(cin>>num)
	{
		if(num=="0")break;
		int len=num.size();

		int remain=0;
		int cur=0;
		for(int i=0 ; i<len ; i++)
		{
			cur=cur*10+(num[i]-'0');
			remain=cur%17;
			cur=remain;
		}
		remain? cout<<"0\n":cout<<"1\n";
	}
	return 0;
}