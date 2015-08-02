#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#define M 1000000000
using namespace std;

vector <int > PRIME;
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
	while(cin>>n,n)
	{
		int sum=n;
		for(int i=0 ;i<PRIME.size();i++)
		{	
			if(n%PRIME[i]==0)
			{
				while(!(n%PRIME[i]))n/=PRIME[i];	
				sum=sum/PRIME[i]*(PRIME[i]-1);
			}
		}
		if(n!=1)sum=sum/n*(n-1);					//figure out
		cout<<sum<<"\n";
	}
	return 0;
}
//the problem not to find prime just find prime factor so you need to find prime up to extract a square root of MAX bound 