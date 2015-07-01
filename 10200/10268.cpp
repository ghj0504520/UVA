#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>

using namespace std;
long long num_table[500001];
long long convert(string num)
{
	bool sign=0;
	if(num[0]=='-')
	{
		sign=1;
		num[0]='0';
	}
	long long int len=num.size(),sum=0;
	for(int i=0 ; i<len ; i++)
	{
		sum=sum*10+num[i]-'0';
	}
	if(sign)sum*=-1;
	
	return sum;
}
int main()
{
	long long int x;
	string cof,tmp;
	while(cin>>x)
	{
		getchar();
		getline(cin,cof);
		
		stringstream buf(cof);
		long long int num,pos=0;
		while(buf>>tmp)
		{
			num=convert(tmp);
			num_table[pos++]=num;
		}
		
		long long ans=0,n_power=1,power=1;
		for(int i=pos-2 ; i>=0 ; i--)
		{
			ans+=num_table[i]*power*n_power;
			power++;
			n_power*=x;
		}
		cout<<ans<<"\n";
		
	}
	return 0;
}
