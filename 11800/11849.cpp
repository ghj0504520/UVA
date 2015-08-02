#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int n,m;
	while(cin>>n>>m)
	{
		if(!n&&!m)break;

		int ans=0,num;
		map<int ,int >cnt;
		for(int i=0 ; i<n; i++ )
		{
			cin>>num;
			cnt[num]++;
		}

		for(int i=0 ; i<m; i++ )
		{
			cin>>num;
			if(cnt[num]>0)
			{
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}