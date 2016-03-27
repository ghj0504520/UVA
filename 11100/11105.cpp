#include <iostream>
#include <vector>

#define M 1000000+1

using namespace std;

bool Prime[M+10]={0};
vector<int> H;
void seize()
{
	Prime[1]=1;
	for(int i=5 ; i<=M ; i+=4)
		if(!Prime[i])
		{
			H.push_back(i);
			for(int j=i+i ; j<=M ; j+=i)
				Prime[j]=1;
		}
}

bool semiPrime[M+10]={0};
int cnt[M+10]={0};
void solveH()
{
	int len=H.size();
	for(int i=0 ; i<=len ; i++)
	{
		for(int j=i ; j<=len ; j++)
		{
			if((long long)H[i]*H[j]>M)break;
			
			semiPrime[H[i]*H[j]]=1;
		}
	}

	for(int i=1 ; i<=M ; i++)
	{
		if(semiPrime[i])cnt[i]=1;
		cnt[i]+=cnt[i-1];
	}
}

int main()
{
	seize();
	solveH();
	int q;
	while(cin>>q,q)
	{
		cout<<q<<" "<<cnt[q]<<"\n";
	}
	return 0;
}