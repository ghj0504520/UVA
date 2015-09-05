#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int LIS(vector <int> lis)
{
	int len=lis.size();
	vector <int>dpLIS;
	dpLIS.push_back(lis[0]);

	for(int i=1 ; i<len ; i++)
	{
		if(lis[i] > dpLIS.back())
		{
			dpLIS.push_back(lis[i]);
		}
		else
		{
			*lower_bound(dpLIS.begin(),dpLIS.end(),lis[i])=lis[i];
		}
	}
	return dpLIS.size();
}

int main()
{
	int num,t=0;
	while(cin>>num)
	{
		if(num==-1)break;
		vector <int> lis;
		while(1)
		{
			lis.push_back(num);
			cin>>num;
			if(num==-1)break;
		}
		if(t)cout<<"\n";
		cout<<"Test #"<<++t<<":\n";
		reverse(lis.begin(),lis.end());
		int num=LIS(lis);
		cout<<"  maximum possible interceptions: "<<num<<"\n";
	}
	return 0;
}