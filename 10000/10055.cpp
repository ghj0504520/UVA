#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	long long a,b;
	while(cin>>a>>b)
	{	
		a-=b;
		if(a<0)a=a*(-1);
		cout<<a<<'\n';
	}	
}
