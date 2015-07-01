#include<iostream>
#include<stack>
#include<stdio.h>
using namespace std;

bool open(char in)
{
	if(in=='('||in=='['||in=='{'||in=='<')
		return 1;
	return 0;
}

bool close(char in)
{
	if(in==')'||in==']'||in=='}'||in=='>')
		return 1;
	return 0;
}

int main()
{
	string query;
	
	while(getline(cin,query))
	{
		stack <char> check;
		int correct=1;
		int len=query.length(),count=0;
		for(int i=0;i<len;i++)
		{
			count++;
			if(open(query[i]))
			{
				if(query[i]=='('&&query[i+1]=='*')
				{
					check.push('*');
					i++;
				}
				else
					check.push(query[i]);	
			}
			else if(close(query[i]) ||(query[i]=='*'&&query[i+1]==')'))
			{
				if(check.empty())
				{
					correct=0;
					break;
				}
				if(query[i]==')')
				{
					if(check.top()!='(')
					{
						correct=2;
						break;
					}
					check.pop();
				}
				else if(query[i]==']')
				{
					if(check.top()!='[')
					{
						correct=2;
						break;
					}
					check.pop();
				}
				else if(query[i]=='}')
				{
					if(check.top()!='{')
					{
						correct=2;
						break;
					}
					check.pop();
				}
				else if(query[i]=='>')
				{
					if(check.top()!='<')
					{
						correct=2;
						break;
					}
					check.pop();
				}
				else if(query[i]=='*'&&query[i+1]==')')
				{
					if(check.top()!='*')
					{
						correct=2;
						break;
					}
					check.pop();
					i++;
				}
			}
		}
		if(!check.empty()&&correct!=2)
		{
			count++;
			correct=0;
		}
		if(!correct || correct==2)
		{
			cout<<"NO "<<count<<"\n";
		}
		else if(correct==1)
		{
			cout<<"YES\n";
		}
	}
	return 0;
}
