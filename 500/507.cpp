#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct bound
{
	int x,y;
	bound (int ix,int iy)
	{
		x=ix;
		y=iy;
	}
	bool operator<(const bound&p)const
	{
		return p.x>x ||(p.x==x &&p.y<y);
	}
};
int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	for(int i=0 ; i<t ; i++)
	{
		int node;
		cin>>node;
		int weight[node];
		for(int j=0 ; j<node-1 ; j++)
		{
			cin>>weight[j];
		}
		int s=1,t,tmp=0,ans=0;
		vector <bound > order;
		for(int j=0 ; j<node-1 ; j++)							//get the max cost by DP
		{
			tmp+=weight[j];
			if(tmp>=ans)										//because ask for lowest bound
			{													//use a vector to store the bound
				if(tmp>ans)										//which has same cost
				{
					order.clear();
				}
				ans=tmp;
				t=j+2;
				order.push_back(bound(s,t));
			}
			if(tmp<0)
			{
				tmp=0;
				s=j+2;
			}
			
		}
		sort(order.begin(),order.end());						//sort the vector to get lowest bound
		
		if(!ans)
			cout<<"Route "<<i+1<<" has no nice parts";
		else 
			cout<<"The nicest part of route "<<i+1<<" is between stops "<<order[0].x<<" and "<<order[0].y;
		cout<<'\n';
	}
	return 0;
}
