#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct peace
{
	int len,wid;
};
void swap(int *s,int *b)
{
	int swap=*s;
	*s=*b;
	*b=swap;
}
bool cmp(const peace &i,const peace &j)
{
	return i.len<j.len || (i.len==j.len&&i.wid<j.wid);
}
int rec(peace data[])
{
	int length=data[0].len,wideth=data[0].wid,height;
	if(!(data[2].wid==wideth || data[2].wid==length || data[2].len==length || data[2].len==wideth))
		return 0;	
	else
	{
		if(data[2].len==length)
			height=data[2].wid;
		else if(data[2].wid==length)
			height=data[2].len;
		else if(data[2].len==wideth)
			height=data[2].wid;
		else if(data[2].wid==wideth)
			height=data[2].len;
	}
	if(data[4].wid!=wideth && data[4].wid!=length && data[4].len!=wideth && data[4].len!=length)
		return 0;	
	else
	{
		if(data[4].len==length && height!=data[4].wid)
			return 0;
		else if(data[4].wid==length && height!=data[4].len)
			return 0;
		else if(data[4].len==wideth && height!=data[4].wid)
			return 0;
		else if(data[4].wid==wideth && height!=data[4].len)
			return 0;
	}
	return 1;
}
int main()
{
	int l,w;
	peace data[6];
	while(cin>>l)
	{
		cin>>w;
		if(l>w)
			swap(&l,&w);
		data[0].len=l;
		data[0].wid=w;
		for(int i=1;i<6;i++)
		{
			cin>>l>>w;
			if(l>w)
				swap(&l,&w);
			data[i].len=l;
			data[i].wid=w;
		}
		sort(data,data+6,cmp);
		bool check=1;
		for(int i=0;i<6;i+=2)
		{
			if(!(data[i].len==data[i+1].len && data[i].wid==data[i+1].wid))
			{
				check=0;
				break;
			}
		}
		if(!check || !rec(data))
			cout<<"IMPOSSIBLE\n";
		else
			cout<<"POSSIBLE\n";
	}
	return 0;
}
