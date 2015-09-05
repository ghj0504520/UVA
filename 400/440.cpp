#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int n,m;
	while(cin>>n,n)
	{
		m=0;
		int ans;
		while(1)
		{
			m++;
			int remain=0;
			for(int k=2; k<n; k++)
			{
				remain=(remain+m)%k;
			}
			if(remain==0)
			{
				ans=m;
				break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}