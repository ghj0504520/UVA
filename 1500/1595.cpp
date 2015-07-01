#include <iostream>
#include <set>
using namespace std;

struct point
{
	long long  x,y;
	point (long long  px,long long  py)
	{
		x=px;
		y=py;
	}
	bool operator<(const point &p)const
	{
		return p.x < x || (p.x == x && p.y < y);
	}
};


int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		set <point> table;
		long long sum=0,num;
		cin>>num;
		for(int i=0 ; i<num ; i++)
		{
			long long x,y;
			cin>>x>>y;
			x*=num;
			point data(x,y);
			sum+=x;
			table.insert(data);
		}
		sum/=num;
		bool correct=1;
		for(set <point>::iterator it=table.begin() ; it!=table.end() ; it++)
		{
			if(table.find(point(2*sum-it->x,it->y))==table.end())
			{
				correct=0;
				break;
			}
		}
		if(correct)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
