#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	string num;
	while(cin>>num)
	{
		int cur,max=1,len=num.length(),sum=0;
		for(int i=0 ; i<len ; i++)
		{
			cur=0;
			if(isdigit(num[i]))
				cur=num[i]-'0';
			else if(isalpha(num[i]))
			{
				if(num[i]>='A' && num[i]<='Z')
					cur=num[i]-'A'+10;
				else if(num[i]>='a' && num[i]<='z')
					cur=num[i]-'a'+10+26;
			}
			sum+=cur;
			if(cur>max)max=cur;
		}
		int check=0;
		for(int i=max ; i<=62 ; i++)
		{
			if(sum%i==0)
			{
				check=i;
				break;
			}
		}
		if(check)
		{
			cout<<check+1<<'\n';
		}
		else if(!check)
		{
			cout<<"such number is impossible!\n";
		}
	}
	return 0;
}
