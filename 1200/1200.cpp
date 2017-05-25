#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

void cal(string s,int &x,int &c)
{
	int sum=0;
	int len=s.size();
	bool nag=0;
	for(int i=0 ; i<len ; i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			sum=10*sum+(s[i]-'0');
		}
		else if(s[i]=='-')
		{
			if(nag)sum*=-1;
			c+=sum;
			nag=1;
			sum=0;
		}
		else if(s[i]=='+')
		{
			if(nag)sum*=-1;
			c+=sum;
			nag=0;
			sum=0;
		}
		else if(s[i]=='x')
		{
			if(nag)sum*=-1;
			x+=(sum==0? (s[i-1]=='0'?0: (nag?-1:1)) :sum);
			sum=0;
			nag=0;
		}
	}
	if(nag)sum*=-1;
	c+=sum;
	//cout<<x<<" "<<c<<"\n";
}

int main()
{
	int T;
	cin>>T;
	for(int t=0 ; t<T ; t++)
	{
		string in;
		cin>>in;
		int len=in.size();
		for(int i=0 ; i<len ; i++)
			if(in[i]=='=')
				in[i]=' ';

		stringstream buf(in);
		string left,right;
		buf>>left>>right;

		int leftX=0,leftC=0,rightX=0,rightC=0;
		cal(left,leftX,leftC);
		cal(right,rightX,rightC);

		if(leftX==rightX&&leftC==rightC)
			cout<<"IDENTITY\n";
		else if(leftX==rightX&&leftC!=rightC)
			cout<<"IMPOSSIBLE\n";
		else cout<<(int)floor((double)(rightC- leftC)/(leftX- rightX))<<"\n";
	}
	return 0;
}