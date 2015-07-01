#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int num;
	while(cin>>num)
	{
		if(!num)
			break;
		priority_queue< int , vector<int> , greater<int> > data;       //figure out
		int in;
		for(int i=0;i<num;i++)
		{
			cin>>in;
			data.push(in);
		}
		int n1,n2,sum=0,cost=0;
		while(1)
		{
			sum=0;
			if(!data.empty())
			{
				n1=data.top();
				sum+=n1;
				data.pop();
			}
			if(!data.empty())
			{
				n2=data.top();
				sum+=n2;
				data.pop();
				data.push(sum);
				cost+=sum;
			}
			else
			{
				break;
			}
		}cout<<cost<<'\n';
	}
	return 0;
}
