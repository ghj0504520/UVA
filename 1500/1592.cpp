#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

string modify(string in)
{
	int len=in.size();
	for(int i=0 ; i<len ; i++)
	{
		if(in[i]==' ')in[i]='_';
		else if(in[i]==',')in[i]=' ';
	}
	return in;
}

int main()
{
	ios::sync_with_stdio(0);
	int R,C;
	while(cin>>R>>C)
	{
		cin.ignore();
		string line;
		map<string,int>table;
		int cnt=0;
		int dp[10001][11]={0};
		for(int i=0 ; i<R ; i++)
		{
			getline(cin,line);
			line=modify(line);
			stringstream buf(line);
			string tok;
			for (int j = 0; j < C; ++j)
			{
				buf>>tok;
				if(table.find(tok)==table.end())
				{
					table.insert(std::pair<string,int>(tok,cnt++));
					dp[i][j]=cnt-1;
				}
				else
				{
					dp[i][j]=table[tok];
				}
			}
		}

		map<long long,int >check;
		bool fail=0;
		for(int j=0 ; j<C-1 ;j++)
		{
			for(int k=j+1 ; k<C;k++)
			{
				check.clear();
				long long value;
				for(int i=0 ; i<R ; i++)
				{
					value=(long long)dp[i][j]*100000+dp[i][k];
					if(check.find(value)==check.end())
					{
						check.insert(std::pair<long long,int >(value,i+1));
					}
					else
					{
						fail=1;
						cout<<"NO\n";
						cout<<check[value]<<" "<<i+1<<"\n";
						cout<<j+1<<" "<<k+1<<"\n";
						break;
					}
				}if(fail)break;
			}if(fail)break;
		}
		if(!fail)cout<<"YES\n";
	}
	return 0;
}