#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const double PI =acos(-1);

int main()
{
	int r,arc;
	string deg;
	while(cin>>r>>arc>>deg)
	{
		double ans,degree;
		if(deg=="min")
			degree=(double)arc/60;
		else
			degree=(double)arc;
		if(degree>180.0)
			degree=360.0-degree;
			
		ans=PI*2*(r+6440.0)*degree/360;
		printf("%.6lf ",ans);
		ans=(double)2*(r+6440.0)*sin(PI/180*degree/2);
		printf("%.6lf\n",ans);
	}
	return 0;
}
