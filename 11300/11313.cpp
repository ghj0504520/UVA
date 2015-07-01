#include <iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n ,m ,ans=0;
		cin>>n>>m;
		bool check=1;
		while(1)
		{
			if(n<m)
			{
				check=0;
				break;
			}
			ans++;
			n-=m;
			n++;
			if(n==1)break;
		}
		if(!check)
			cout<<"cannot do this\n";
		else
			cout<<ans<<"\n";
	}
	return 0;
}
