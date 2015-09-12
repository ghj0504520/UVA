#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int LIS(vector<int>A,vector<int>B)
{
	vector<int>record[250*250+10];
	int len1=A.size(),len2=B.size();

	for(int i=0 ; i<len2 ; i++)
		record[ B[i] ].push_back(i);

	vector<int>vlis;
	vlis.push_back(-1);
	for (int i = 0; i < len1; ++i)
	{
		int len =record[A[i]].size();
		for (int j=len-1 ; j>=0 ; j--)
		{
			int cur=record[A[i]][j];

			if(cur>vlis.back())
			{
				vlis.push_back(cur);
			}
			else
			{
				*lower_bound(vlis.begin(),vlis.end(),cur)=cur;
			}
		}
	}
	return vlis.size()-1;
}
int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	for(int i=0 ; i<T ; i++)
	{
		int n,p,q,v;
		cin>>n>>p>>q;
		vector<int>A,B;
		for(int i=0 ; i<=p ; i++)
		{
			cin>>v;
			A.push_back(v);
		}
		for(int i=0 ; i<=q ; i++)
		{
			cin>>v;
			B.push_back(v);
		}
		int ans=LIS(A,B);
		cout<<"Case "<<i+1<<": "<<ans<<"\n";
	}

	return 0;
}