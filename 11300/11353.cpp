#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int table[2000010];
struct data
{
	int cnt,num;

	bool operator <(const data &i)const
	{
		return i.cnt>cnt || (i.cnt==cnt&&i.num>num);
	}
}T[2000010];
void sieve()
{
	memset(table,0,sizeof(table));
	for(int i=2;i<=2000000;i++)
	{
		if(!table[i])
			for(int j=i+i;j<=2000000;j+=i)
			{
				if(!table[j]&&j%i==0)
					table[j]=j/i;
			}
	}
	for(int i=0 ; i<=2000000;i++)
	{
		if(!table[i])table[i]=1;
		else
			table[i]=1+table[ table[i] ];

		T[i].cnt=table[i];
		T[i].num=i;
	}
	sort(T,T+2000001);
}

int main()
{
	ios::sync_with_stdio(0);
	sieve();
	int query,t=0;
	while(cin>>query,query)
	{	
		cout<<"Case "<<++t<<": "<<T[query].num<<"\n";
	}
	return 0;
}