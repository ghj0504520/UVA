#include<iostream>
using namespace std;
int main()
{
	int t;
	while(cin>>t)
	{
		int a,f,t_out=0;
		for(int i=0;i<t;i++)
		{
			t_out++;
			cin>>a>>f;
			int t_in=0;
			for(int _f=0;_f<f;_f++)
			{
				t_in++;
				for(int _a=1;_a<=a;_a++)
				{
					for(int print_a=0;print_a<	_a;print_a++)
					{
						cout<<_a;
					}cout<<'\n';
				}
				for(int _b=a-1;_b>0;_b--)
				{
					for(int print_b=_b;print_b>0;print_b--)
					{
						cout<<_b;
					}cout<<'\n';
				}
				if(t_in!=f)cout<<'\n';
			}if(t_out!=t)cout<<'\n';
		}
	}
}
