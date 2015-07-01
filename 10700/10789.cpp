#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
using namespace std;

bool prime(int num)
{
	for(int i=2 ; i<=sqrt(num) ; i++)
	{
		if(!(num%i))
			return 0;
	}
	return 1;
}
int main()
{
	int n,table[127];
	cin>>n;
	for(int t=0 ; t<n ; t++)
	{
		cout<<"Case "<<t+1<<": ";
		memset(table,0,sizeof(table));
		string in;
		cin>>in;
		int len=in.size();
		for(int i=0 ; i<len ; i++)
		{
			table[(int)in[i]]++;
		}
		bool empty=0;
		for(int i=0 ; i<127 ; i++)
		{
			if(table[i]>1 && prime(table[i]))
			{
				empty=1;
				cout<<(char)i;
			}
		}
		if(!empty)cout<<"empty";
		cout<<'\n';
	}
	return 0;
}
