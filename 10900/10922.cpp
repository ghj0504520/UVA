#include <iostream>
#include <stdio.h>

using namespace std;

int token(int num)
{
	int sum=0;
	while(num>0)
	{
		sum=sum+(num%10);
		num/=10;
	}
	return sum;
}

int main()
{
	string number;
	while(cin>>number)
	{
		if(number=="0")
			break;
		long long nine=0,len=number.length();
		for(int i=0 ; i<len ; i++)
		{
			nine+=number[i]-'0';
		}
		if(!(nine%9))
		{
			int t=1;
			while(nine!=9)
			{
				nine=token(nine);
				t++;
				//cout<<nine<<"\n";
			}
			cout<<number<<" is a multiple of 9 and has 9-degree "<<t<<".\n";
		}
		else
		{
			cout<<number<<" is not a multiple of 9.\n";
		}
	}
	return 0;
}
