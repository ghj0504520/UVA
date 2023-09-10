#include <iostream>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
	string in;
	int num;
	cin>>num;
	while(num--)
	{
		cin>>in;
		int l = in.length();
		map<char,int>cnt;

		for(int i=0 ; i<l ; i++)
			cnt[in[i]]= (cnt[in[i]]==0)?1:cnt[in[i]]+1;

		int ans = 1000 ;

		ans = (cnt['M']<=ans)?cnt['M']:ans;
		ans = (cnt['A']/3 <=ans)?cnt['A']/3:ans;
		ans = (cnt['R']/2 <=ans)?cnt['R']/2:ans;
		ans = (cnt['G']<=ans)?cnt['G']:ans;
		ans = (cnt['I']<=ans)?cnt['I']:ans;
		ans = (cnt['T']<=ans)?cnt['T']:ans;

		cout<<ans<<"\n"; 
	}
	return 0;
}