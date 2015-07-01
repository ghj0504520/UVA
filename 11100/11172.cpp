#include<iostream>
using namespace std;
struct data
{
	int a,b;
};
int main()
{
	int read;
	while(cin>>read)
	{
		data in;
		for(int i=0;i<read;i++)
		{
			cin>>in.a>>in.b;
			if(in.a<in.b)
				cout<<'<';
			else if(in.a>in.b)
				cout<<'>';
			else if(in.a==in.b)
				cout<<'=';
			
			cout<<'\n';
		}
		
	}
}
