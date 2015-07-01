#include <iostream>
#include <cmath>
using namespace std;

long long cut(long long num)
{
	if(!num)return 1;
	
	return cut(num-1)+num;
}
int main()
{
	long long ask;
	while(cin>>ask)
	{
		if(ask<0)break;
		
		cout<<cut(ask)<<"\n";
	}
	return 0;
}
