#include <iostream>
#include <cctype>

using namespace std;

int getLen(string in)
{
	int len=in.size(),ans=0;
	for(int i=0 ; i<len ; i++)
		if(isalpha(in[i])||in[i]=='-')
			ans++;
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	string in,ans;
	int MAX=-1;
	while(cin>>in)
	{
		if(in=="E-N-D")break;

		int cur=getLen(in);
		if(cur>MAX)
		{
			ans=in;
			MAX=cur;
		}
	}
	int ansLen=ans.size();
	for(int i=0 ; i<ansLen ; i++)
	{
		if(isalpha(ans[i])||ans[i]=='-')
		{
			cout<<(char)tolower(ans[i]);
		}
	}
	cout<<"\n";
	return 0;
}