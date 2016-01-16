#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int remain;
int standard(string in)
{
	int i,j,len=in.size();
	for(i=0 ; i<len ; i++)
		if(in[i]=='.')break;
	for(j=i;j<len-1;j++)
		in[j]=in[j+1];
	in.resize(len-1);
	remain=len-i-1;

	stringstream buf(in);
	int ans;
	buf>>ans;
	return ans;
}

int digit[10000];
void bigProduct(int num,int p)
{
	memset(digit,0,sizeof(digit));
	digit[0]=1;
	for(int i=0 ; i<p ; i++)
	{
		for(int j=0 ; j<10000 ; j++)
		{
			digit[j]*=num;
		}
		for(int j=1 ; j<10000 ; j++)
		{
			if(digit[j-1]>10)
			{
				digit[j]+=digit[j-1]/10;
				digit[j-1]%=10;
			}
		}
	}
}

void output()
{
	int max,min;
	for(int i=0 ; i<10000 ; i++)
		if(digit[i])
		{
			min=i;
			break;
		}
	for(int i=10000-1 ; i>=0 ; i--)
		if(digit[i])
		{
			max=i;
			break;
		}
	if(remain<=max)
	{
		for(int i=max ; i>=min ; i--)
		{
			cout<<digit[i];
			if(min!=max&&i==remain)cout<<".";
		}
	}
	else 
	{
		cout<<".";
		for(int i=remain-1 ; i>=min ; i--)
		{
			if(i>max)cout<<"0";
			else cout<<digit[i];
		}
	}
	cout<<"\n";
}

int main()
{
	string in;
	int num,power;
	while(cin>>in>>power)
	{
		num=standard(in);
		bigProduct(num,power);
		remain*=power;
		output();
	}
	return 0;
}