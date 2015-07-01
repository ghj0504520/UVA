#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	string in;
	while(cin>>in)
	{
		if(in=="#")break;
		
		string after_sort=in;
		sort(after_sort.begin(),after_sort.end());
		next_permutation(in.begin(),in.end());
		
		if(after_sort==in)
			cout<<"No Successor\n";
		else 
			cout<<in<<'\n';
	}
	return 0;
}
