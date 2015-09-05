#include <iostream>

using namespace std;

int main()
{
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
			if(remain==11)
			{
				ans=m;
				break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}