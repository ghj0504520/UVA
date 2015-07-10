#include <iostream>

using namespace std;

long long Collatz_Sequence(long long I,long long L)
{
	long long t=1;
	while(I != 1)
	{
		t++;
		if(I%2==0)	I/=2;
		else
		{
			if(3*I+1 > L)
			{
				t--;
				break;
			}else I=3*I+1;
		}
	}
	return t;
}
int main()
{
	ios::sync_with_stdio(0);
	long long init,limit,r=0;
	while(cin>>init>>limit)
	{
		if(init==-1&&limit==-1)break;
		r++;
		long long ans=Collatz_Sequence(init,limit);
		cout<<"Case "<<r<<": A = "<<init<<", limit = "<<limit<<", number of terms = "<<ans<<"\n";
	}
	return 0;
} 