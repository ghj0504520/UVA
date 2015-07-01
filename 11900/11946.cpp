#include <iostream>
#include <cctype>
#include <cstdio>
using namespace std;

char check(char ch)
{
	switch(ch)
	{
		case'0':return 'O';
		case'1':return 'I';
		case'2':return 'Z';
		case'3':return 'E';
		case'4':return 'A';
		case'5':return 'S';
		case'6':return 'G';
		case'7':return 'T';
		case'8':return 'B';
		case'9':return 'P';
		default:return ch;
	}
}
string modify(string in)
{
	int len=in.size();
	for(int i=0 ; i<len ; i++)
	{
		in[i]=check(in[i]);
	}
	return in;
}
int main()
{
	//freopen("out","w",stdout);
	string line;
	int n;
	cin>>n;
	n--;
	getchar();
	while(n>=0)
	{	
		getline(cin,line);
		if(line=="")
		{
			if(n>=1)cout<<"\n";
			n--;
		}
		else
		{
			line=modify(line);
			cout<<line<<"\n";
		}
	}
	return 0;
}
