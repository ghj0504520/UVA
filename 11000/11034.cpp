#include <iostream>
#include <queue>
using namespace std;
 
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int l, m;
		cin>>l>>m;
		l = l*100;
		queue<int> Side[2];
 
		int car;
		string side;
		while(m--)
		{
			cin>>car>>side;
			if(side=="left")
			{
				Side[0].push(car);
			}else
			{
				Side[1].push(car);
			}
		}
 
		int cnt = 0;
		int sum = 0;
		bool dir = 0 ;
		while(!Side[0].empty() || !Side[1].empty())
		{
			sum = 0;
			while(!Side[dir].empty() && Side[dir].front()+sum<=l)
			{
				sum+=Side[dir].front();
				Side[dir].pop();
			}
 
			cnt++;
			dir = !dir;
		}cout<<cnt<<"\n";
	}
	return 0;
}