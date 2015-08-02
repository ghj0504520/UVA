#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#define M 2147483647
using namespace std;

vector <long long> PRIME;
 void prime_init()
 {
 	PRIME.push_back(2);
 	int sq=sqrt(M);
 	for (int i = 3; i <=sq ; i+=2)
 	{
 		int check=1,subsq=sqrt(i);
 		for (int j = 2; j <=subsq; ++j)
 			if(!(i%j))check=0;
 		if(check)PRIME.push_back(i);
 	}
 }

int main()
{
	prime_init();
	int n;
	while(cin>>n)
	{
		int tmp=n;
		if(n==1)							//figure out
		{
			cout<<"0\n";
			continue;
		}
		int sum=n;
		vector<int> cnt;
		for(int i=0 ;i<PRIME.size();i++)
		{	
			if(n%PRIME[i]==0)
			{
				int c=0;
				while(!(n%PRIME[i]))
				{
					n/=PRIME[i];	
					c++;
				}
				cnt.push_back(c);
				sum=sum/PRIME[i]*(PRIME[i]-1);
			}
		}
		if(n!=1)							//figure out
		{
			cnt.push_back(1);
			sum=sum/n*(n-1);
		}
		long long factor_num=1;
		for(int i=0 ; i<cnt.size();i++)
			factor_num*=(cnt[i]+1);
		cout<<tmp- sum- factor_num +1<<"\n";
	}
	return 0;
}
//the problem not to find prime just find prime factor so you need to find prime up to extract a square root of MAX bound 

//answer = query_number  -  euler_function_number  -  factor_sum_count  +  1