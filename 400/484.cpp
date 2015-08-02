#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main()
{
	map<int, int> table;
	queue<int >order;
	int num;
	while(cin>>num)
	{
		if(table[num]==0)
		{
			order.push(num);
		}
		table[num]++;
	}
	while(!order.empty())
	{
		int cur=order.front();
		cout<<cur<<" "<<table[cur]<<"\n";
		order.pop();
	}
	return 0;
}