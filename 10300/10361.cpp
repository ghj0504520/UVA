#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int T;
	cin>>T;
	cin.ignore();
	while(T--)
	{
		string a,b,p1,p2,p3,p4;
		getline(cin,a);
		getline(cin,b);
		int la=a.size(),lb=b.size(),idx=0;
		while(a[idx]!='<')cout<<a[idx++];
		idx++;
		while(a[idx]!='>')p1+=a[idx++];
		idx++;
		while(a[idx]!='<')p2+=a[idx++];
		idx++;
		while(a[idx]!='>')p3+=a[idx++];
		idx++;
		while(idx<la)p4+=a[idx++];
		cout<<p1<<p2<<p3<<p4<<"\n";

		for (int i = 0; i < lb &&b[i]!='.'; ++i)
			cout<<b[i];
		cout<<p3<<p2<<p1<<p4<<"\n";
	}
	return 0;
}