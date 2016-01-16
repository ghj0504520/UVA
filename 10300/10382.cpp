#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct Range
{
	double LX,RX;
	Range(double p,double r,double w)
	{
		double move=sqrt(r*r-w*w);
		LX=p-move;
		RX=p+move;
	}
	bool operator<(const Range& pos)const
	{
		return RX>pos.RX;
	}
};

int main()
{
	int num;
	double L,W;
	while(cin>>num>>L>>W)
	{
		vector<Range> table;
		for(int i=0 ; i<num ; i++)
		{
			double p ,r;
			cin>>p>>r;

			if(r >= W/2)table.push_back(Range(p,r,W/2));
			else table.push_back(Range(0,0,0));
		}
		sort(table.begin(),table.end());

		double cur=0;
		int cnt=0;
		bool flag=0;

		while(1)
		{
			if(cur>=L)break;
			flag=0;
			for(int i=0 ; i<num ; i++)
			{
				if(table[i].LX<=cur && table[i].RX>cur)
				{
					flag=1;
					cur=table[i].RX;
					cnt++;
					break;
				}
			}
			if(!flag)break;
		}
		cout<< ((cur>=L)? cnt:-1)<<endl;
	}
	return 0;
}