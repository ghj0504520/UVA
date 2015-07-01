#include <iostream>
#include <sstream>
using namespace std;

void modify(string &in)
{
	int len=in.size();
	for(int i=0 ; i<len ; i++)
	{
		if(in[i]=='/')
			in[i]=' ';
	}
}

double table[127]={0};
bool check(string compse)
{
	int len=compse.size();
	double sum=0;
	for(int i=0 ; i<len ; i++)
		sum+=(double)table[(int)compse[i]];
	return sum==1.0? 1 : 0;
}
int main()
{
	string line;
	table[(int)'W']=(double)1;
	table[(int)'H']=(double)1/2;
	table[(int)'Q']=(double)1/4;
	table[(int)'E']=(double)1/8;
	table[(int)'S']=(double)1/16;
	table[(int)'T']=(double)1/32;
	table[(int)'X']=(double)1/64;
	while(cin>>line)
	{
		if(line=="*")break;
		modify(line);
		
		stringstream buf(line);
		string compose;
		int crt=0;
		while(buf>>compose)
		{
			if(check(compose))
				crt++;
		}
		cout<<crt<<'\n';
	}
	return 0;
}
