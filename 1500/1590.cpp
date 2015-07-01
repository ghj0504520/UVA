#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct ip
{
	int n[4];
	ip ()
	{
		n[0]=n[1]=n[2]=n[3]=0;
	}
	void print()
	{
		cout<<n[0]<<"."<<n[1]<<"."<<n[2]<<"."<<n[3]<<"\n";
	}
}add[1000];
bool cmp(const ip &i,const ip &j)
{
	return i.n[0]<j.n[0] || (i.n[0]==j.n[0] &&i.n[1]<j.n[1]) || (i.n[0]==j.n[0] &&i.n[1]==j.n[1] &&i.n[2]<j.n[2]) || (i.n[0]==j.n[0] &&i.n[1]==j.n[1]&&i.n[2]==j.n[2] &&i.n[3]<j.n[3]);
}
int num_bit(int n)
{
	int res=0;
	while(n>0)
	{
		n/=2;
		res++;
	}
	return res;
}
int consec_one(ip a,ip b)
{
	int res=0;
	for(int i=0 ; i<4 ; i++)
	{
		if(a.n[i]!=b.n[i])
		{
			res+=8-num_bit(a.n[i]^b.n[i]);
			break;
		}
		else
			res+=8;
	}
	return res;
}
int main()
{
	
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			scanf("%d.%d.%d.%d",&add[i].n[0],&add[i].n[1],&add[i].n[2],&add[i].n[3]);
		
		sort(add,add+n,cmp);
		
		int num=consec_one(add[0],add[n-1]);
		int part=(num)/8;
		ip mask;
		for(int i=0 ; i<part ; i++)
			mask.n[i]=255;
		int m=8-(num-part*8);
		mask.n[part]=(255>>m)<<m;
		
		ip minadd;
		for(int i=0 ; i<4 ; i++)
			minadd.n[i]=add[0].n[i]&mask.n[i];
		
		minadd.print();
		mask.print();	
	}
	return 0;
}
