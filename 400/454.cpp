#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

string check(string in)
{
	string out="\0";
	int len=in.size();
	sort(in.begin(),in.end());
	for(int i=0 ; i<len ; i++)
	{
		if(isalpha(in[i]))
			out+=in[i];
	}
	return out;
}
int main()
{
	int n;
	cin>>n;
	getchar();
	getchar();
	for(int i=0 ; i<n ; i++)
	{
		if(i)cout<<"\n";
		int pos=0;
		string tmp,data[150],modify[150];
		while(getline(cin,tmp))
		{
			if(tmp=="\0")break;
			data[pos++]=tmp;
		}
		sort(data,data+pos);
		for(int m=0 ; m<pos ; m++)
		{
			modify[m]=check(data[m]);
		}
		for(int m=0 ; m<pos ; m++)
		{
			for(int c=m+1 ; c<pos ; c++)
			{
				if(modify[c]==modify[m])
					cout<<data[m]<<" = "<<data[c]<<"\n";
			}
		}
	}
	return 0;
}
