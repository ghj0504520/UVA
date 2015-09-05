#include <iostream>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

long long chain(string in)
{
	sort(in.begin(),in.end());
	string s,r;
	s=in;
	r=in;
	reverse(s.begin(),s.end());
	stringstream b1(s),b2(r);
	long long n1,n2;
	b1>>n1;
	b2>>n2;
	cout<<n1<<" - "<<n2<<" = ";
	n1-=n2;
	cout<<n1<<"\n";
	return n1;
}

int main()
{
	ios::sync_with_stdio(0);
	string num;
	while(cin>>num)
	{
		if(num=="0")break;	
		cout<<"Original number was "<<num<<"\n";
		long long t=0;
		string pre="-1";
		set<string>table;
		while(1)
		{
			long long ans=chain(num);
			stringstream buf;
			buf<<ans;
			buf>>num;
			if(table.count(num))break;
			pre=num;
			table.insert(pre);
			t++;
		}
		cout<<"Chain length "<<t+1<<"\n\n";
	}
	return 0;
}