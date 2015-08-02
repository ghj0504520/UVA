#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int prime[50001];
 void prime_init()
 {
 	memset(prime,0,sizeof(0));
 	prime[0]=1;
 	prime[1]=1;
 	for(int i=2; i<=50000;i++)						//similar to DP each prime number calculate euler number first 
 		if(!prime[i])
 			for(int j=i;j<=50000;j+=i)
 			{	
 				if(!prime[j])
 					prime[j]=j;
 				prime[j]=prime[j]/i*(i-1);
 			}
 }

int main()
{
	ios::sync_with_stdio(0);
	int q;
	prime_init();
	while(cin>>q,q)
	{
		long long sum=0,ans;
		for (int r = 2; r <= q; ++r)
		{
			sum+=prime[r]*2;
		}
		cout<<sum+1<<"\n";
	}
	return 0;
}