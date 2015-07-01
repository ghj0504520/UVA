#include<iostream>
#include<cstdio>
#include<string.h>
#include<cstdlib>
using namespace std;
int main()
{
	
	int sp,ask;
	while(cin>>sp>>ask)
	{
		string special[sp],spans[sp];
		string q;
		
		for(int i=0;i<sp;i++)
			cin>>special[i]>>spans[i];
		while(ask--)
		{
			cin>>q;
			bool  spq=0;
			for(int i=0;i<sp;i++)
			{
				if(q==special[i])
				{	cout<<spans[i]<<'\n';
					spq=1;
				}
			}
			int len=q.size();
			if(spq==0)
			{
				if(q[len-2]!='a'&&q[len-2]!='e'&&q[len-2]!='i'&&q[len-2]!='o'&&q[len-2]!='u'&&q[len-1]=='y')
				{
					
					for(int i=0;i<len-1;i++)
						cout<<q[i];
					cout<<"ies\n";
				}
				else if(q[len-1]=='o')
				{
					
					for(int i=0;i<len;i++)
						cout<<q[i];
					cout<<"es\n";
				}
				else if(q[len-1]=='s')
				{
					
					for(int i=0;i<len;i++)
						cout<<q[i];
					cout<<"es\n";
				}
				else if(q[len-1]=='x')
				{
					
					for(int i=0;i<len;i++)
						cout<<q[i];
					cout<<"es\n";
				}
				else if(q[len-1]=='h'&&q[len-2]=='c')
				{
					
					for(int i=0;i<len;i++)
						cout<<q[i];
					cout<<"es\n";
				}
				else if(q[len-1]=='h'&&q[len-2]=='s')
				{
					
					for(int i=0;i<len;i++)
						cout<<q[i];
					cout<<"es\n";
				}
				else
				{
					for(int i=0;i<len;i++)
						cout<<q[i];
					cout<<"s\n";
				}
			}
		}
		
	}		
	
}	

