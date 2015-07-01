#include <iostream>
#include <stack>
#include <queue>
#include <stdio.h>
using namespace std;

int cmd[10000],data[10000];

int test_stack(int n)
{
	stack<int> s;
	for(int i=0 ; i<n ; i++)
	{
		if(cmd[i]==1)
		{
			s.push(data[i]);
		}
		else if(cmd[i]==2)
		{
			if(s.empty())return 0;
			int h=s.top();
			if(h!=data[i])
				return 0;
			
			s.pop();
		}
	}
	return 1;
}

bool test_queue(int n)
{
	queue<int> q;
	for(int i=0;i<n;i++)
	{
		if(cmd[i]==1)
		{
			q.push(data[i]);
		}
		else if(cmd[i]==2)
		{
			if(q.empty())return 0;
			int h=q.front();
			if(h!=data[i])
				return 0;
			
			q.pop();
		}
	}
	return 1;
}

bool test_priority(int n)
{
	priority_queue<int> p;
	for(int i=0;i<n;i++)
	{
		if(cmd[i]==1)
		{
			p.push(data[i]);
		}
		else if(cmd[i]==2)
		{
			if(p.empty())return 0;
			int h=p.top();
			if(h!=data[i])
				return 0;
			
			p.pop();
		}
	}
	return 1;
}
int main()
{
	int num;
	while(cin>>num)
	{
		for(int i=0;i<num;i++)
		{
			cin>>cmd[i]>>data[i];
			
		}
		int flag=0,ans=0;
		
		if(test_stack(num))
		{
			ans=1;
			flag++;
		}
		if(test_queue(num))
		{
			ans=2;
			flag++;
		}
		if(test_priority(num))
		{
			ans=3;
			flag++;
		}
		if(!flag)
		{
			printf("impossible\n");
		}
		else if(flag==1)
		{
			if(ans==1)
			{
				printf("stack\n");
			}
			else if(ans==2)
			{
				printf("queue\n");
			}
			else
			{
				printf("priority queue\n");
			}
		}
		else
		{
			printf("not sure\n");
		}	
	}
	return 0;
}
