#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
	int fact[4]={2,3,5,7};
	set<long long>humbleNum;
	humbleNum.insert(1);
	set<long long>::iterator it=humbleNum.begin();
	while(humbleNum.size()<10000)
	{
		for(int i=0 ; i<4 ; i++ )
		{
			long long cur=(*it) * fact[i];
			if(!humbleNum.count(cur))
				humbleNum.insert(cur);
		}
		it++;
	}
	vector<long long> v(humbleNum.begin(),humbleNum.end());
	long long query;
	while(cin>>query,query)
	{
		cout<<"The "<<query;
		if(query%100>10&&query%100<20)
		{
			cout<<"th";
		}
		else
		{
			int mod=query%10;
			if(mod==1)
			{
				cout<<"st";
			}
			else if(mod==2)
			{
				cout<<"nd";
			}
			else if(mod==3)
			{
				cout<<"rd";
			}
			else
			{
				cout<<"th";
			}
		}
		cout<<" humble number is "<<v[query-1]<<".\n";
	}
	return 0;
}