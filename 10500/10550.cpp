#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
	int s,n1,n2,n3,sum;
	while(cin>>s>>n1>>n2>>n3)
	{
		if(!s && !n1 && !n2 && !n3)break;
		sum=1080;
		sum+=((s-n1+40)%40)*9;
		sum+=((n2-n1+40)%40)*9;
		sum+=((n2-n3+40)%40)*9;
	
		cout<<sum<<'\n';
	}
	
	return 0;
}
