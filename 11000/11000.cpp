#include <iostream>

using namespace std;

int main()
{
	int T;
	while(cin>>T)
	{
		if(T==-1)break;

		long long f=1,m=0,curf,curm;

		for(int i=0 ; i<T ; i++)
		{
			curf=m+1;
			curm=f+m;
			f=curf;
			m=curm;
		}
		cout<<m<<" "<<m+f<<"\n";
	}
	return 0;
}