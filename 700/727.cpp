#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
bool isop(char c)
{
	return c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')';
}

int priop(char c)
{
	switch(c)
	{
		case'*':
		case'/':return 3;
		case'+':
		case'-':return 2;
		case'(':return 1;
		default:return 0;
	}
}

string mid2pos(string in)
{
	int len=in.size();
	string pos="";
	stack<int> tmp;
	for(int i=0 ; i<len ; i++)
	{
		if(isop(in[i]))
		{
			if(tmp.empty()||in[i]=='(')
				tmp.push(in[i]);
			else
			{
				if(in[i]==')')
				{
					while(tmp.top()!='(')
					{
						char cur=tmp.top();
						pos+=cur;
						tmp.pop();
					}
					tmp.pop();
				}
				else
				{
					while(!tmp.empty()&&priop(in[i])<=priop(tmp.top()))
					{
						char cur=tmp.top();
						pos+=cur;
						tmp.pop();
					}
					tmp.push(in[i]);
				}
			}
		}
		else
			pos+=in[i];
	}
	while(!tmp.empty())
	{
		char cur=tmp.top();
		pos+=cur;
		tmp.pop();
	}
	return pos;
}
int main()
{
	//freopen("out","w",stdout);
	int n;
	cin>>n;
	n--;
	getchar();
	getchar();
	while(n>=0)
	{
		string c;
		string pos="";
		while(getline(cin,c))
		{
			if(c=="\0")break;
			pos+=c;
		}
		pos=mid2pos(pos);
		cout<<pos<<"\n";
		n--;
		if(n>=0)cout<<"\n";
	}
}
