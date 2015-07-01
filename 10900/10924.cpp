#include <iostream>
#include <cmath>
using namespace std;

bool isprime(int n)
{
	int sq=sqrt(n);
	for(int i=2 ; i<=sq ; i++)
		if(n%i==0)return 0;
	return 1;
}

int main()
{
	string word;
	while(cin>>word)
	{
		int len=word.length(),sum=0;
		for(int i=0 ; i<len ; i++)
		{
			if(word[i]>='a'&&word[i]<='z')
			{
				sum+=word[i]-'a'+1;
			}
			else if(word[i]>='A'&&word[i]<='Z')
			{
				sum+=word[i]-'A'+1+26;
			}
		}
		if(sum>=2)
		{
			if(isprime(sum))
			{
				cout<<"It is a prime word.\n";
			}
			else
			{
				cout<<"It is not a prime word.\n";
			}
		}
		else
			cout<<"It is a prime word.\n";
	}
	return 0;
}
