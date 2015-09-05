#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dpLIS[10000+10],dpLDS[10000+10];
void LIS(vector<int>S)
{
	vector<int>lis;
	int len=S.size();
	lis.push_back(S[0]);
	dpLIS[0]=1;
	for(int i=1 ; i<len ; i++)
	{
		if(S[i] > lis.back())
		{
			lis.push_back(S[i]);
		}
		else
		{
			*lower_bound(lis.begin(),lis.end(),S[i])=S[i];
		}
		dpLIS[i]=lis.size();
	}
}
void LDS(vector<int>S)
{
	vector<int>lds;
	int len=S.size();
	lds.push_back(S[len-1]);
	dpLDS[len-1]=1;
	for(int i=len-2 ; i>=0 ; i--)
	{
		if(S[i] > lds.back())
		{
			lds.push_back(S[i]);
		}
		else
		{
			*lower_bound(lds.begin(),lds.end(),S[i])=S[i];
		}
		dpLDS[i]=lds.size();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	int num;
	while(cin>>num)
	{
		vector<int>seq;
		for(int i=0 ; i<num ; i++)
		{
			int n;
			cin>>n;
			seq.push_back(n);
		}
		LIS(seq);
		LDS(seq);
		int len=seq.size();
		int ans=0;
		for(int i=0 ; i<len ; i++)
		{
			ans=max(ans,min(dpLIS[i],dpLDS[i]));
		}
		cout<<2*ans-1<<"\n";
	}
	return 0;
}