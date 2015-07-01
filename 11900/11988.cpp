#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
using namespace std;

int main()
{
	string in;
	while(cin>>in)
	{
		list <char> broken;
		int len=in.size();
		list <char> ::iterator it=broken.begin();
		for(int i=0 ; i<len ; i++)
		{
			if(in[i]=='[')it=broken.begin();
			
			else if(in[i]==']')it=broken.end();
			
			else broken.insert(it,in[i]);
		}
		
		for(it=broken.begin() ; it!=broken.end() ; it++)
			cout<<*it;
		cout<<'\n';
	}
	return 0;
}

