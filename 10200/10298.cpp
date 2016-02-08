#include <iostream>

using namespace std;

int fValue[1000000+10];
void fail(string &query)
{
	int len=query.size();
	fValue[0]=-1;

	for(int i=1 ; i<len ; i++)
	{
		int cur=fValue[i-1];

		while(cur>=0 && query[cur+1]!=query[i])
			cur=fValue[cur];
		
		if(query[cur+1]==query[i])
			cur++;

		fValue[i]=cur;
	}
}

int main()
{
	string s;
	while(cin>>s)
	{
		if(s==".")break;

		fail(s);

		int last=fValue[s.size()-1];

		s.size()%(s.size()-1-last)?cout<<1:cout<<s.size()/(s.size()-1-last);
		cout<<"\n";
	}
	return 0;
}