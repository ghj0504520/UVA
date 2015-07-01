#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int table[10000][128];
void code_table(char h[],int len)
{
	memset(table,0,sizeof(table));
	int pos=1;
	table[1][0]=h[0];
	for(int i=2 ; ; i++)
	{
		for(int j=0 ; j<pow(2,i)-1 ; j++)
		{
			//cout<<i<<" "<<j<<" ";
			table[i][j]=h[pos++];
			//cout<<(char)table[i][j]<<'\n';
			if(h[pos]=='\0')return ;
		}
	}
}

int read_char()
{
	while(1)
	{
		int ch=getchar();
		if(ch!='\n'&&ch!=' ') return ch;
	}
}

int read_int(int length)
{
	int value=0;
	while(length--)
	{
		value=2*value+read_char()-'0';
	}
	return value;
}

void decode()
{
	while(1)
	{
		int encode_len=read_int(3);
		//cout<<encode_len<<'\n';
		if(!encode_len)
		{
			//cout<<encode_len<<"end of file\n";
			return ;
		}
		int word_value;
		while(1)
		{
			word_value=read_int(encode_len);
			if(word_value==(pow(2,encode_len)-1))
			{
				//cout<<word_value<<"finish\n";
				break;
			}
			cout<<(char)table[encode_len][word_value];
		}
	}
}

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	char head[1000];
	while(cin.getline(head,999))
	{
		int len=strlen(head);
		code_table(head,len);
		decode();
		cout<<"\n";
		getchar();
		
	}
	return 0;
}
