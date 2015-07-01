#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main()
{
	long long int cur=1;
	priority_queue<long long int,vector<long long int>,greater<long long int> > ugly;
	map <long long int ,bool > uglytable;
	int multi[3]={2,3,5};
	ugly.push(cur);
	uglytable[cur]=1;
	cout<<"The 1500'th ugly number is ";
	for(int i=1 ; i<=1500 ; i++)
	{
		cur=ugly.top();
		if(i==1500)cout<<cur<<".\n";
		ugly.pop();
		for(int j=0;j<3;j++)
		{
			long long int tmp=cur*multi[j];
			if(!uglytable[tmp])
			{
				uglytable[tmp]=1;
				ugly.push(tmp);
			}
		}
	}
	return 0;
}
