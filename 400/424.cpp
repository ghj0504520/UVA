#include <iostream>

using namespace std;

int main()
{
	int ans[150]={0};
	string in;
	while(cin>>in)
	{
		if(in=="0")break;

		int idx=0,len=in.size();
		for(int i=len-1 ; i>=0 ; i--)
		{
			ans[idx]=ans[idx]+(in[i]-'0');
			idx++;
		}
		for(int i=1 ; i<150 ; i++)
		{
			if(ans[i-1]>9)
			{
				ans[i]+=ans[i-1]/10;
				ans[i-1]%=10;
			}
		}
	}
	bool p=0;
	for(int i=149 ; i>=0 ; i--)
	{
		if(ans[i]&&!p)p=1;
		if(p)cout<<ans[i];
	}cout<<"\n";
	return 0;
}