#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int t=0 ; t<T ; t++)
	{
		if(t)cout<<"\n";
		int n,i;
		cin>>n;
		int p[1000+10]={0};
		for(i=0 ; i<n ; i++)
			cin>>p[i];
		sort(p,p+n);

		int sum=0;
		vector<string>ans;

		for(i=n-1 ; i>=3 ; i-=2)
		{
			int caseA=p[1]+p[0]+p[i]+p[1];
			int caseB=p[i-1]+p[0]+p[i]+p[0];
			
			if(caseA<caseB)
			{
				sum+=caseA;
				ans.push_back(to_string(p[0])+' '+to_string(p[1]));
				ans.push_back(to_string(p[0]));
				ans.push_back(to_string(p[i-1])+' '+to_string(p[i]));
				ans.push_back(to_string(p[1]));
			}
			else
			{
				sum+=caseB;
				ans.push_back(to_string(p[0])+' '+to_string(p[i-1]));
				ans.push_back(to_string(p[0]));
				ans.push_back(to_string(p[0])+' '+to_string(p[i]));
				ans.push_back(to_string(p[0]));
			}
		}
		if(i==2)
		{
			sum+=(p[1]+p[0]+p[2]);
			ans.push_back(to_string(p[0])+' '+to_string(p[1]));
			ans.push_back(to_string(p[0]));
			ans.push_back(to_string(p[0])+' '+to_string(p[2]));
		}
		else if(i==1)
		{
			sum+=p[1];
			ans.push_back(to_string(p[0])+' '+to_string(p[1]));
		}
		else if(i==0)
		{
			sum+=p[0];
			ans.push_back(to_string(p[0]));
		}
		cout<<sum<<"\n";
		int len=ans.size();
		for(i=0 ; i<len ; i++)
			cout<<ans[i]<<"\n";
		
	}
	return 0;
}