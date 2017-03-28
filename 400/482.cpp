#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	int T ;
	cin>>T;
	getchar();
	getchar();
	while(T--)
	{
		string order,data;
		getline(cin,order);
		getline(cin,data);
		getchar();

		int tmp,max=-1;
		vector<int>idx;
		stringstream buf1(order);
		while(buf1>>tmp)
		{
			idx.push_back(tmp);
			if(max<tmp)max=tmp;
		}

		string tmp1;
		vector<string>ans(max+1);
		stringstream buf2(data);
		for(int i=0 ; i<max ; i++)
		{
			buf2>>ans[idx[i]];
		}

		for(int i=1 ; i<=max ; i++)
		{
			cout<<ans[i]<<"\n";
		}
		if(T)cout<<"\n";
	}
	return 0;
}
