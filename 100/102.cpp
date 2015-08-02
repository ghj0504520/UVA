#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	int g[3],b[3],c[3];
	while(cin>>b[0])
	{
		cin>>g[0]>>c[0]>>b[1]>>g[1]>>c[1]>>b[2]>>g[2]>>c[2];
		string name[6]= { "BCG", "BGC", "CBG", "CGB", "GBC", "GCB" };
		int cnt[6];
		cnt[0]=b[1]+b[2]+c[0]+c[2]+g[0]+g[1];
		cnt[1]=b[1]+b[2]+g[0]+g[2]+c[0]+c[1];
		cnt[2]=c[1]+c[2]+b[0]+b[2]+g[0]+g[1];
		cnt[3]=c[1]+c[2]+g[0]+g[2]+b[0]+b[1];
		cnt[4]=g[1]+g[2]+b[0]+b[2]+c[0]+c[1];
		cnt[5]=g[1]+g[2]+c[0]+c[2]+b[0]+b[1];

		int min=2147483647,mindex;
		for(int i=0 ; i<6 ; i++)
		{
			if(cnt[i]<min)
			{
				min=cnt[i];
				mindex=i;
			}
		}
		cout<<name[mindex]<<" "<<min<<"\n";
	}
	return 0;
}