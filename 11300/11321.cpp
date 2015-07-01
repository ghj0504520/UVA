#include <iostream>
#include <algorithm>
using namespace std;

struct number
{
	long num;
	long mod;
};
int m;
bool cmp(const number &i,const number &j)
{
	if(i.mod != j.mod)
		return i.mod < j.mod;
	else if(i.mod == j.mod)
	{
		if (i.num%2 && j.num%2)
		{
			return i.num > j.num;
		}
		else if (!(i.num%2) && !(j.num%2))
		{
			return i.num < j.num;
		}
		else
		{
			return i.num%2;          //figure out
		}
	}
}
int main()
{
	int n;
	while(cin>>n>>m)
	{
		cout<<n<<' '<<m<<'\n';
		if(!n && !m)break;
		
		number table[n];
		for(int i=0 ; i<n ; i++)
		{
			cin>>table[i].num;
			table[i].mod=table[i].num%m;
		}
		sort(table,table+n,cmp);
		
		
		for(int i=0 ; i<n ; i++)
			cout<<table[i].num<<'\n';
	}
	return 0;
}
