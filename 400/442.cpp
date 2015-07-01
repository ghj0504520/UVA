#include <iostream>
#include <map>
#include <stack>
#include <cctype>

using namespace std;

struct matrix
{
	int x,y;
};
int main()
{
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	matrix m[26];
	for(int i=0 ; i<n ; i++)
	{
		char c;
		cin>>c;
		cin>>m[c-'A'].x>>m[c-'A'].y;
	}
	
	string line;
	while(cin>>line)
	{
		int len=line.size(),ans=0;
		stack <matrix> op;
		bool error=1;
		for(int i=0 ; i<len ; i++)
		{
			if(isalpha(line[i]))
			{
				op.push(m[line[i]-'A']);
			}
			else if(line[i]==')')
			{
				matrix m2=op.top();
				op.pop();
				matrix m1=op.top();
				op.pop();
				
				if(m1.y!=m2.x)
				{
					error=0;
					break;
				}
				else
				{
					ans+=m1.x*m2.x*m2.y;
					matrix after;
					after.x=m1.x;
					after.y=m2.y;
					op.push(after);
				}
			}
		}
		if(!error)
			cout<<"error\n";
		else
			cout<<ans<<'\n';
	}
	return 0;
}
