#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <sstream>

#define M 1000000

using namespace std;

bool prime[M+10]={0};
void seize()
{
	prime[0]=1;
	prime[1]=1;
	for(int i=2 ; i<=M ; i++)
	{
		if(!prime[i])
			for(int j=i+i ; j<=M ; j+=i)
				prime[j]=1;
	}
}

string convert(int num)
{
	stringstream buf;
	buf<<num;
	string ans;
	buf>>ans;
	return ans;
}

int cprime[M+10]={0};
void circular_prime()
{
	for(int i=1 ; i<=M ; i++)
	{
		cprime[i]=cprime[i-1];
		if(!prime[i])
		{
			string numString=convert(i);
			bool check=1;
			int len=numString.size();
			for(int m=0 ; m<len ; m++)
			{
				//cout<<numString<<"\n";

				string after="";
				for(int l=1 ; l<len ; l++)
					after+=numString[l];
				after+=numString[0];
				numString=after;

				stringstream buf(after);
				int ans;
				buf>>ans;
				if(prime[ans])
				{
					check=0;
					break;
				}
			}
			if(check)
			{
				//cout<<i<<"\n";
				cprime[i]++;
			}
		}
	}
}

int main()
{
	seize();
	circular_prime();

	int A,B;
	while(cin>>A)
	{
		if(A==-1)break;

		cin>>B;

		int sum=cprime[B]-cprime[A-1];

		if (sum <= 0)
			printf("No Circular Primes.\n");
		else if (sum == 1)
			printf("1 Circular Prime.\n");
		else
			printf("%d Circular Primes.\n", sum);
	}
	return 0;
}