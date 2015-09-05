#include <iostream>
#include <vector>
#include <sstream>
#include <cstdio>
using namespace std;

int dpLIS[20000];
int record[20000];
int index;

int LIS(vector<int>lis)
{
	for(int i=0 ; i<20000 ; i++)dpLIS[i]=1;
	for(int i=0 ; i<20000 ; i++)record[i]=-1;
	int len=lis.size();
	for(int i=0 ; i<len ; i++)
	{
		for(int j=i+1 ; j<len ; j++)
		{
			if(lis[i] < lis[j])
			{
				if(dpLIS[i]+1 > dpLIS[j])
				{
					dpLIS[j]=dpLIS[i]+1;
					record[j]=i;
				}
			}
		}
	}
	int maxI,maxV=0;
	for(int i=0 ; i<len ; i++)
	{
		if(dpLIS[i]>maxV)
		{
			maxV=dpLIS[i];
			maxI=i;
		}
	}
	index=maxI;
	return maxV;

}
void getLIS(vector<int>lis,int idx)
{
	if(record[idx]==-1)
	{
		cout<<lis[idx]<<"\n";
	}
	else
	{
		getLIS(lis,record[idx]);
		cout<<lis[idx]<<"\n";;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	int num;
	cin>>num;
	cin.ignore();
	cin.ignore();
	for(int i=0 ; i<num ; i++)
	{
		string in;
		vector<int> lis;
		while(getline(cin,in))
		{
			if(in=="")break;
			stringstream buf(in);
			int n;
			buf>>n;
			lis.push_back(n);
		}
		if(i)cout<<"\n";
		if(lis.size()>0)
		{
			int length=LIS(lis);
			cout<<"Max hits: "<<length<<'\n';
			getLIS(lis,index);
		}
		else
		{
			cout<<"Max hits: "<<0<<'\n';
		}
	}
	return 0;
}