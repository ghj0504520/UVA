#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int B,N;
	while(cin>>B>>N)
	{
		if(!B&&!N)break;

		int reserve[B];
		for(int i=0 ; i<B ; i++)cin>>reserve[i];

		for(int i=0 ; i<N ; i++)
		{
			int d,c,m;
			cin>>d>>c>>m;
			reserve[d-1]-=m;
			reserve[c-1]+=m;
		}
		char mode='S';
		for(int i=0 ; i<B ; i++)
		{
			if(reserve[i]<0)
			{
				mode='N';
				break;
			}
		}
		cout<<mode<<"\n";
	}
	return 0;
}