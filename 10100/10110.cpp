#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long ask;
	while(cin>>ask)
	{
			if(!ask)break;
			
			long long sq=sqrt(ask);
			
			sq*sq==ask?cout<<"yes\n":cout<<"no\n";

	}
	return 0;
}
