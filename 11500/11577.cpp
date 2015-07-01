#include <iostream>
#include <cctype>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	cin>>n;
	getchar();
	for(int t=0 ; t<n ; t++)
	{
		string in;
		getline(cin,in);
		
		int len=in.size();
		int table[30]={0};
		
		for(int i=0 ; i <len ; i++)
		{
			if(isalpha(in[i]))
				table[tolower(in[i])-'a']++;
		}	
		int min=0;
		for(int i=0 ; i<30 ; i++)
		{
			if(table[i]>min)
			{
				min=table[i];
			}
		}
		for(int i=0 ; i<30 ; i++)
		{
			if(table[i]==min)
			{
				cout<<(char)(i+'a');
			}
		}
		cout<<'\n';
	}
	return 0;
}
