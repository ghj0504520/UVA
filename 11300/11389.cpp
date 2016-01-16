#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n,sum,r;
	while(cin>>n>>sum>>r)
	{
		if(!n&&!sum&&!r)break;

		vector<int>moring,evening;
		for(int i=0 ; i<n ; i++)
		{
			int num;
			cin>>num;
			moring.push_back(num);
		}
		for(int i=0 ; i<n ; i++)
		{
			int num;
			cin>>num;
			evening.push_back(num);
		}
		sort(moring.begin(),moring.end());
		sort(evening.begin(),evening.end());
		reverse(evening.begin(),evening.end());

		int ans=0;
		for(int i=0 ; i<n ; i++)
		{
			int V=moring[i]+evening[i];
			if(V>sum)
			{
				ans+=V-sum;
			}
		}
		cout<<ans*r<<"\n";

	}
	return 0;
}