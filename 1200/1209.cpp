#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int differ(string in)
{
	int len=in.size();
	int ans=1000;
	for(int i=0 ; i<len-1 ; i++)
	{
		if(abs(in[i]-in[i+1])<ans)
			ans=abs(in[i]-in[i+1]);
	}
	return ans;
}
int main()
{
	string name;
	while(cin>>name)
	{
		int value=0;
		string after=name,before=name,ans;
		for(int i=0;i<=10;i++)
		{
			//cout<<before<<' '<<value<<'\n';
			if(value<=differ(before))
			{
				value=differ(before);
				ans=before;
			}
			prev_permutation(before.begin(),before.end());
		}
		for(int i=0;i<=10;i++)
		{
			//cout<<after<<' '<<value<<'\n';
			if(value<differ(after))
			{
				value=differ(after);
				ans=after;
			}
			next_permutation(after.begin(),after.end());
		}
		cout<<ans<<value<<'\n';
	}
	return 0;
}
