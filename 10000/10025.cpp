#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		long long Q;
		cin>>Q;
		Q=abs(Q);
		long long idx=1,SUM=0;
		while(SUM<Q)
			SUM+=idx++;

		idx--;

		SUM=(1+idx)*idx/2;

		while((SUM-Q)%2)
		{
			SUM+=++idx;
		}

		if(Q)cout<<idx<<'\n';
		else if(!Q) cout<<"3\n";

		if(T)cout<<'\n';
	}
	return 0;
}