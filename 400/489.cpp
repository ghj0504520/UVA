#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

bool check(int table[])
{
	for(int i=0;i<26;i++)
	{
		if(table[i]==1)
			return 0;
	}
	return 1;
}
int main()
{
	//freopen("out","w",stdout);
	int Round;
	while(1)
	{
		cin>>Round;
		if(Round==-1)break;
		string ans;
		int table[26]={0};
		cin>>ans;
		int len=ans.length();
		for(int i=0;i<len;i++)
		{
			table[ans[i]-'a']=1;
		}
		string guess;
		
		cin>>guess;
		int t=0,len1=guess.length();
		
		for(int i=0;i<len1;i++)
		{
			if(table[guess[i]-'a']==1)
			{
				table[guess[i]-'a']=2;
				
			}
			else if(!table[guess[i]-'a'])
			{
				table[guess[i]-'a']=3;
				t++;
			}
			if(t>=7 ||check(table))break;
			
			
			
		}
		
		cout<<"Round "<<Round<<"\n";
		if(t>=7)
			cout<<"You lose.\n";
		else 
		{
			if(check(table))
				cout<<"You win.\n";
			else
				cout<<"You chickened out.\n";
		}
	}
	return 0;
}
