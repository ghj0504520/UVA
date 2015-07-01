#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int convert(int cost[],int num,int base)
{
	int sum=0;
	while(num>0)
	{
		int temp=num%base;
		num/=base;
		sum+=cost[temp];
	}return sum;
}
struct table
{
	int index;
	int value;
};
bool cmp(const table &i,const table &j)
{
	return i.value < j.value ||(i.value==j.value && i.index<j.index);
}
int main()
{
	int t;
	while(cin>>t)
	{
		for(int i=1;i<=t;i++)
		{
			if(i!=1)cout<<'\n';
			cout<<"Case "<<i<<":\n";
			int data[36];
			for(int n=0;n<36;n++)
					scanf("%d",&data[n]);
			int ask,query;
			
			cin>>ask;
			for(int k=0;k<ask;k++)
			{
				cin>>query;
				cout<<"Cheapest base(s) for number "<<query<<":";
			
				table chbase[37];
				chbase[0].index=0;
				chbase[0].value=10000000;
				chbase[1].index=1;
				chbase[1].value=10000000;
			
				for(int ch=2;ch<=36;ch++)
				{
					chbase[ch].index=ch;
					chbase[ch].value=convert(data,query,ch);
				}
				sort(chbase,chbase+37,cmp);
				int min=chbase[0].value;
				for(int p=0;p<=36;p++)
				{
					
					if(chbase[p].value==min)
						cout<<' '<<chbase[p].index;
				}cout<<'\n';
			}
		}
	}
	return 0;
}
