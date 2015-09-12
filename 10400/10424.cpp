#include <iostream>
#include <cctype>
#include <cstdio>

using namespace std;

int convert(string in)
{
	int ans=0;
	int len=in.size();
	for(int i=0 ; i<len ; i++)
	{
		if(isalpha(in[i]))
		{
			if(in[i]>='a' && in[i]<='z')
			{
				ans+=(in[i]-'a'+1);
			}
			else
			{
				ans+=(in[i]-'A'+1);
			}
		}
	}
	return ans;
}

int deal(int num)
{
	int ans=0;
	while(num>0)
	{
		ans+=num%10;
		num/=10;
	}
	return ans;
}
int main()
{
	string a,b;
	while(getline(cin,a))
	{
		getline(cin,b);
		int A=convert(a),B=convert(b);
		while(A>9)A=deal(A);
		while(B>9)B=deal(B);
		
		if(B<A)
		{
			int s=A;
			A=B;
			B=s;
		}

		printf("%.2lf ",100.0*A/B);
		cout<<"%\n";
	}
	return 0;
}