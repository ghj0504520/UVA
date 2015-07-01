#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
using namespace std;

int count[20][20];

void print_r(char m[20][20],int r,int c)
{
	for(int i=0 ; i<r ; i++)
	{
		for(int j=0 ; j<c ; j++)
		{
			if(count[i][j])
			{
				printf("%3d.",count[i][j]);
				while(m[i][j]!='*'&&j<c)
				{
					cout<<m[i][j++];
				}
				cout<<'\n';
			}
		}
	}
}
void print_c(char m[20][20],int r,int c)
{
	for(int i=0 ; i<r ; i++)
	{
		for(int j=0 ; j<c ; j++)
		{
			if(count[i][j])
			{
				int move=i;                             //figure out
				printf("%3d.",count[i][j]);
				while(m[move][j]!='*'&&move<r)
				{
					cout<<m[move++][j];
					count[move-1][j]=0;
				}
				cout<<'\n';
			}
		}
	}
}

int main()
{
	int r,c,t=0;
	while(cin>>r)
	{
		if(!r)break;
		cin>>c;
		if(t)cout<<'\n';
		cout<<"puzzle #"<<++t<<":\n";
		char mp[20][20];
		memset(count,0,sizeof(count));
		for(int i=0 ; i<r ; i++)
			for(int j=0 ; j<c ; j++)
				cin>>mp[i][j];
		int num=0;
		for(int i=0 ; i<r ; i++)                            //array count 
		{
			for(int j=0 ; j<c ; j++)
			{
				if(mp[i][j]!='*')
				{
					if(!i || !j)count[i][j]=++num;
					else if(mp[i-1][j]=='*' || mp[i][j-1]=='*')count[i][j]=++num;
				}
			}
		}
		cout<<"Across\n";
		print_r(mp,r,c);
		cout<<"Down\n";
		print_c(mp,r,c);
		
	}
	return 0;
}
