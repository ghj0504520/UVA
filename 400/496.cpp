#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
	string a,b;
	while(getline(cin,a))
	{
		getline(cin,b);

		vector<int>sA,sB;

		stringstream bufA(a),bufB(b);
		int tmp;
		while(bufA>>tmp)
		{
			sA.push_back(tmp);
		}
		while(bufB>>tmp)
		{
			sB.push_back(tmp);
		}
		sort(sA.begin(),sA.end());
		sort(sB.begin(),sB.end());
		vector<int> intersect;

		set_intersection(sA.begin(),sA.end(),sB.begin(),sB.end(),std::inserter(intersect,intersect.begin()));

		int len=intersect.size();
		int len1=sA.size(),len2=sB.size();
		if(len==min(len1,len2))
		{
			if(len1==len2)
			{
				cout<<"A equals B\n";
			}else if(len==len1) 
			{
				cout<<"A is a proper subset of B\n";
			}else
			{
				cout<<"B is a proper subset of A\n";
			}

		}else if(len==0)
		{
			cout<<"A and B are disjoint\n";
		}else
		{
			cout<<"I'm confused!\n";
		}
	}
	return 0;
}