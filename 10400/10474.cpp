#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num,qnum,t=0;
	while(cin>>num>>qnum)
	{
		if(!num&&!qnum)break;
		int stone[num];
		for(int i=0;i<num;i++)
			cin>>stone[i];
		sort(stone,stone+num);
		int q;
		cout<<"CASE# "<<++t<<":\n";
		for(int i=0;i<qnum;i++)
		{
			cin>>q;
			cout<<q;
			if(!binary_search(stone,stone+num,q))
				cout<<" not found\n";
			else
				cout<<" found at "<<lower_bound(stone,stone+num,q)-stone+1<<'\n';      //figure out
		}
	}
	return 0;
}
