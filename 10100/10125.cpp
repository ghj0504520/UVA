#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
struct data
{
	long long a,b;
	
	data (long long i,long long j)
	{
		a=i;
		b=j;
	}
};
map <long long ,vector<data> > table;

bool Check(long long c,long long d)
{
	long long val=d-c;
	if(table.find(val)==table.end())
		return 0;
	else
	{
		int len=table[val].size();
		for(int i=0 ; i<len ;i++)
			if(table[val][i].a!=c && table[val][i].a!=d && table[val][i].b!=c && table[val][i].b!=d)
				return 1;
		return 0;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	int n;
	while(cin>>n,n)
	{
		table.clear();
		long long S[n];
		for(int i=0 ; i<n ; i++)
			cin>>S[i];
		sort(S,S+n);
		for(int i=0 ; i<n ; i++)
		{
			for(int j=i+1 ; j<n ; j++)
			{
				long long sum=S[i]+S[j];
				table[sum].push_back(data (S[i],S[j]));
			}
		}
		bool check=0;
		long long ans;
		for(int i=n-1 ; i>=0 ; i--)
		{
			for(int j=n-1 ; j>=0 ; j--)
			{
				if(i!=j && Check(S[j],S[i]))
				{
					ans=S[i];
					check=1;
					break;
				}
			}
			if(check)break;
		}
		if(check)
			cout<<ans<<"\n";
		else
			cout<<"no solution\n";
	}
	return 0;
}
