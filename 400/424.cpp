#include <iostream>
#include <cstring>

using namespace std;

int ans_len;

void convert(int tmp[],char origin[])
{
	int pos=0,len=strlen(origin);
	for(int i=len-1 ; i>=0 ; i--)
	{
		tmp[pos++]=origin[i]-'0';
	}
	ans_len=pos;
}
void carry(int ans[])
{
	int l;
	for(int i=0 ; i<=ans_len+20 ; i++)
	{
		if(ans[i]>9)
		{
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
		l=i;
	}
	ans_len=l;
}
void additive(int tmp[],int ans[])
{
	for(int i=0 ; i<=ans_len ; i++)
	{
		ans[i]+=tmp[i];
	}
	carry(ans);
	
}
void print_num(int ans[])
{
	int pos=0;
	for(int i=ans_len ; i>=0 ; i--)
	{
		if(ans[i])
		{
			pos=i;
			break;
		}
	}
	for(int i=pos ; i>=0 ; i--)
	{
		cout<<ans[i];
	}
}

int main()
{
	char bignum[10000];
	int ans[10000]={0};
	while(cin>>bignum)
	{	
		if(bignum[0]=='0'&&bignum[1]=='\0')
			break;
		int temp[10000];
		memset(temp,0,sizeof(temp));
		convert(temp,bignum);
		additive(temp,ans);
		
	}print_num(ans);
	cout<<'\n';
	return 0;
}
