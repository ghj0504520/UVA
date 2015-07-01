#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int num,cal=0;
	while(cin>>num)
	{
		if(cal)
			cout<<"\n";
		cal++;
		if(!num)
			break;
		int ask[num];
		while(cin>>ask[0])
		{
			if(!ask[0])
				break;
			for(int i=1;i<num;i++)
				cin>>ask[i];
			
			stack <int>A;
			for(int i=num;i>0;i--)
				A.push(i);

			stack <int>temp;				
			int s;
			bool check=1;
			for(int i=0;i<num;i++)
			{
				while(temp.empty()||temp.top()!=ask[i])
				{
					if(A.empty())
					{
						check=0;
						break;
					}
					s=A.top();
					A.pop();
					temp.push(s);
				}
				if(!check)break;
				temp.pop();
			}
			if(check)
				cout<<"Yes\n";
			else 
				cout<<"No\n";
		}
	}
	return 0;
}
