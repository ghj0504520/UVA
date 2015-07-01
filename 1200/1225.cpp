#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int count[10]={0};
		string digit;
		int num;
		cin>>num;
		for(int i=1;i<=num;i++)
		{
			char data[1000000];
			sprintf(data,"%d",i);
			digit+=data; 
		}
		
		int len=digit.size();
		for(int i=0;i<len;i++)
		{
			count[(int)digit[i]-'0']++;
		}
		for(int i=0;i<10;i++)
		{
			if(i)cout<<' ';
			cout<<count[i];
		}cout<<'\n';
	}
	return 0;
}
