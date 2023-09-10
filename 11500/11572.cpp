#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,num,len=-1;
		cin>>n;

		set<int> unique;
		queue<int> list;
		for (int i = 0; i < n; ++i)
		{
			cin>>num;

			if(unique.count(num))
			{
				len = max(len,(int)list.size());
				while(list.front()!=num)
				{
					unique.erase(list.front());
					list.pop();
				}list.pop();
			}

			unique.insert(num);
			list.push(num);
		}
		len = max(len,(int)list.size());
		cout<<len<<"\n";
	}
	return 0;
}