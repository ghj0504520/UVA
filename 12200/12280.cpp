#include <iostream>
#include <cctype>

using namespace std;

void standardfy(string input,string &left,string &right)
{
	for(int i=0 ; i<8 ; i++)
		if(input[i]>='A'&&input[i]<='Z')
			left+=input[i];
	
	for(int i=10 ; i<18 ; i++)
		if(input[i]>='A'&&input[i]<='Z')
			right+=input[i];
}

int binaryCnt(char in)
{
	int sum = 0,value=(int)in;

	while(value)
	{
		if(value%2)
			sum+=500;
		else
			sum+=250;
		value/=2;
	}
	return sum;
}

int getWeight(string input)
{
	int ans=0;
	int len=input.size();

	for(int i=0 ; i<len ; i++)
		ans+=binaryCnt(input[i]);
	return ans;
}

void DrawAns(string input)
{
	int len=input.size();
	cout<<input;
	for(int i=len ; i<6 ; i++)cout<<".";
}
void Draw(string left,string right,int mode)
{
	if(mode==0)
	{
		cout<<"........||........\n";
		cout<<".../\\...||.../\\...\n";
		cout<<"../..\\..||../..\\..\n";
		cout<<"./....\\.||./....\\.\n";
		cout<<"/";DrawAns(left);cout<<"\\||/";DrawAns(right);cout<<"\\\n";
		cout<<"\\______/||\\______/\n";
		cout<<"........||........\n";
	}
	else if(mode==1)
	{
		cout<<"........||.../\\...\n";
		cout<<"........||../..\\..\n";
		cout<<".../\\...||./....\\.\n";
		cout<<"../..\\..||/";DrawAns(right);cout<<"\\\n";
		cout<<"./....\\.||\\______/\n";
		cout<<"/";DrawAns(left);cout<<"\\||........\n";
		cout<<"\\______/||........\n";
	}
	else if(mode==2)
	{
		cout<<".../\\...||........\n";
		cout<<"../..\\..||........\n";
		cout<<"./....\\.||.../\\...\n";
		cout<<"/";DrawAns(left);cout<<"\\||../..\\..\n";
		cout<<"\\______/||./....\\.\n";
		cout<<"........||/";DrawAns(right);cout<<"\\\n";
		cout<<"........||\\______/\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	for(int t=0 ; t<T ; t++)
	{
		cout<<"Case "<<t+1<<":\n";
		string tmp;
		string Left="",Right="";
		int Lidx=0,Ridx=0;
		for(int i=0 ; i<8 ; i++)
		{
			cin>>tmp;
			standardfy(tmp,Left,Right);

			if(tmp[1]=='_')Lidx=i;

			if(tmp[11]=='_')Ridx=i;
		}

		int Lvalue=getWeight(Left),Rvalue=getWeight(Right);
		if(Lvalue==Rvalue)
		{
			if(Lidx==Ridx && Lidx==5)
				cout<<"The figure is correct.\n";
			else Draw(Left,Right,0);
		}	
		else if(Lvalue > Rvalue)
		{
			if(Lidx==6 && Ridx==4)
				cout<<"The figure is correct.\n";
			else Draw(Left,Right,1);
		}
		else if(Lvalue < Rvalue)
		{
			if(Lidx==4 && Ridx==6)
				cout<<"The figure is correct.\n";
			else Draw(Left,Right,2);
		}
	}
	return 0;
}