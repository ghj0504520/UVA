#include <iostream>
#include <algorithm>

using namespace std;

int fValue[100000+100];

void fail(string &query)
{
	int len=query.size();
	fValue[0]=-1;

	for(int i=1 ; i<len ; i++)
	{
		int curPrefix=fValue[i-1];

		while(curPrefix>=0 && query[curPrefix+1]!=query[i])
			curPrefix=fValue[curPrefix];

		if(query[curPrefix+1]==query[i])curPrefix++;

		fValue[i]=curPrefix;
	}
}

int KMP(string &s,string &r)
{
	int len=s.size();
	int cur=-1;

	for(int i=0 ; i<len ; i++)
	{
		while(cur>=0&&r[cur+1]!=s[i])
			cur=fValue[cur];

		if(r[cur+1]==s[i])cur++;
	}
	return cur;
}

int main()
{
	string s;
	while(cin>>s)
	{
		string r=s;
		reverse(r.begin(),r.end());
		fail(r);

		int ans=KMP(s,r);

		//cout<<ans<<"\n";
		cout<<s;
		int len=s.size();
		for(int i=ans+1 ; i<len ; i++)cout<<r[i];
		cout<<"\n";
	}
	return 0;
}