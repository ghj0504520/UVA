#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool vectorCmp(const std::pair< vector<int> ,int> &i,const std::pair< vector<int> ,int> &j)
{
	int len=i.first.size();
	for(int p=0 ; p<len ; p++)
	{
		if(i.first[p] < j.first[p])return 1;
		if(i.first[p] > j.first[p])return 0;
	}
	return 0;
}
bool cmp(const std::pair< vector<int> ,int> &i,const std::pair< vector<int> ,int> &j)
{
	int len=i.first.size();
	for(int p=0 ; p<len ; p++)
		if(i.first[p] >= j.first[p])return 0;
	return 1;
}

int dpLIS[50];
int record[50];
int idx;
int LIS(vector< std::pair< vector<int> ,int> >lis)
{
	for(int i=0 ; i<50 ; i++)dpLIS[i]=1;
	for(int i=0 ; i<50 ; i++)record[i]=-1;
	int len=lis.size();
	
	for(int i=0 ; i<len ; i++)
	{
		for(int j=i+1 ; j<len ; j++)
		{
			if(cmp(lis[i],lis[j]))
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
		if(maxV < dpLIS[i])
		{
			maxV=dpLIS[i];
			maxI=i;
		}
	}
	idx=maxI;
	return maxV;
}
void getLIS(vector< std::pair< vector<int> ,int> > BOX,int index)
{
	if(record[index]==-1)
	{
		cout<<BOX[index].second+1;
	}
	else
	{
		getLIS(BOX,record[index]);
		cout<<" "<<BOX[index].second+1;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	int num,dim;
	while(cin>>num>>dim)
	{
		vector< std::pair< vector<int> ,int> >box;
		for (int i = 0; i < num; ++i)
		{
			vector<int>seq;
			for (int j = 0; j < dim; ++j)
			{
				int n;
				cin>>n;
				seq.push_back(n);
			}
			sort(seq.begin(),seq.end());
			box.push_back(std::pair< vector<int> ,int> (seq,i));
		}
		stable_sort(box.begin(),box.end(),vectorCmp);
		
		int ans=LIS(box);
		cout<<ans<<"\n";
		getLIS(box,idx);
		cout<<"\n";
	}
	return 0;
}