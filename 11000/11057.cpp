#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

struct book
{
	int cost,minus;
	bool operator <(const book &pre)const
	{
		return pre.minus > this->minus;
	}
};
bool bsearch(book table[],int s,int d,int key)
{
	int mid=(s+d)/2;
	if(s>d)return 0;
	else
	{
		if(table[mid].minus==key)
			return 1;
		else
		{	
			if(table[mid].minus>key)
				return	bsearch(table, s, mid-1, key);
			else	return	bsearch(table, mid+1, d, key);
		}
	}
}
int main()
{
	int num;
	while(cin>>num)
	{
		book data[10010];
		for (int i = 0; i < num; ++i)
			cin>>data[i].cost;
		int q;
		cin>>q;
		getchar();
		for(int i=0 ; i<num ; i++)
		{
			data[i].minus=q-data[i].cost;
		}
		stable_sort(data,data+num);
		int ans[2]={0, 1000010};
		for(int i=0 ; i<num ; i++)
		{
			//cout<<data[i].cost<<" "<<data[i].minus<<"\n";
			if(bsearch(data,0,num-1,q-data[i].minus))
			{
				//cout<<data[i].cost<<" "<<data[i].minus<<'\n';
				int tmp[2];
				tmp[0]=data[i].cost;
				tmp[1]=data[i].minus;
				sort(tmp,tmp+2);
				if((tmp[0]!=ans[0]&&tmp[1]!=ans[1])&&tmp[1]-tmp[0]<ans[1]-ans[0])
				{
					ans[0]=tmp[0];
					ans[1]=tmp[1];
				}
			}
		}
		cout<<"Peter should buy books whose prices are "<<ans[0]<<" and "<<ans[1]<<".\n\n";
	}
	return 0;
}