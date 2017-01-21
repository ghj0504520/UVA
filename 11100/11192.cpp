#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	string S;
	while(cin>>N,N)
	{
		cin>>S;
		int len = S.size();
		int L=len/N;

		int start=0,dest=start+L;

		for(int i=0 ; i<N ; i++)
		{
			reverse(S.begin()+start,S.begin()+dest);
			start=dest;
			dest=start+L;
		}cout<<S<<"\n";
	}
	return 0;
}