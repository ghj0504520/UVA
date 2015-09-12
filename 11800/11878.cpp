#include <iostream>
#include <sstream>

using namespace std;

void standard(string &in)
{
	int len=in.size();
	string modify="";
	for(int i=0 ; i<len ; i++)
	{
		if(in[i]>='0'&&in[i]<='9')
		{
			modify+=in[i];
		}
		else
		{
			modify=modify+' '+in[i]+' ';
		}
	}
	in=modify;
}

int getAns(int a,int b,char mode)
{
	if(mode=='+')
		return a+b;
	else
		return a-b;
}

bool calculate(string in)
{
	stringstream buf1(in);
	int a1,a2,a3;
	char operate,eq;
	string tmp;
	buf1>>a1;
	buf1>>operate;
	buf1>>a2;
	buf1>>eq;
	buf1>>tmp;
	if(tmp=="?")return 0;

	stringstream buf2(tmp);
	buf2>>a3;
	
	return getAns(a1,a2,operate)==a3;
}

int main()
{
	string EXP;
	int ans=0;
	while(cin>>EXP)
	{
		standard(EXP);
		if(calculate(EXP))ans++;
	}
	cout<<ans<<"\n";
	return 0;
}