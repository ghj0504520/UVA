#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct animal
{
	int W,IQ,id;
	
	animal(int w,int iq,int i)
	{
		W=w,IQ=iq,id=i;
	}
	bool operator <(const animal &i)const
	{
		return IQ>i.IQ || ( IQ==i.IQ&& W<i.W);
	}
};
vector<animal> v;
int dpLIS[1000+10];
int record[1000+10];
int idx;
int LIS()
{
	int len=v.size();

	for(int i=0 ; i<1000+10 ; i++)dpLIS[i]=1;
	for(int i=0 ; i<1000+10 ; i++)record[i]=-1;

	for(int i=0 ; i<len ; i++)
	{
		for(int j=i+1 ; j<len ; j++)
		{
			if(v[i].W<v[j].W &&v[i].IQ!=v[j].IQ )
			{
				if(dpLIS[i]+1 > dpLIS[j])
				{
					dpLIS[j]=dpLIS[i]+1;
					record[j]=i;
				}
			}
		}
	}
	int MaxI,MaxV=0;
	for(int i=0 ; i<len ; i++)
	{
		if(MaxV<dpLIS[i])
		{
			MaxV=dpLIS[i];
			MaxI=i;
		}
	}
	idx=MaxI;
	return MaxV;
}
void getLIS(int index)
{
	if(record[index]!=-1)
	{
		getLIS(record[index]);
		cout<<v[index].id+1<<"\n";
	}
	else
	{
		cout<<v[index].id+1<<"\n";
	}
}
int main()
{
	int w,iq,i=0;
	while(cin>>w>>iq)
	{
		v.push_back(animal(w,iq,i++));
	}
	sort(v.begin(),v.end());
	int ans=LIS();
	cout<<ans<<"\n";
	getLIS(idx);
	return 0;
}