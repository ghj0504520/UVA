#include <stdio.h>
#include <iostream>

using namespace std;

struct side
{
	double x1,y1,x2,y2;
};

int main()
{
	side s[2];
	while(cin>>s[0].x1>>s[0].y1>>s[0].x2>>s[0].y2>>s[1].x1>>s[1].y1>>s[1].x2>>s[1].y2)
	{
		double fx=0.0,fy=0.0,sx=0.0,sy=0.0,samex=0.0,samey=0.0;
		
		if(s[0].x1==s[1].x1 && s[0].y1==s[1].y1)
		{
			samex=s[0].x1;
			samey=s[0].y1;
			fx=s[0].x2;fy=s[0].y2;
			sx=s[1].x2;sy=s[1].y2;
		}
		else if(s[0].x1==s[1].x2 && s[0].y1==s[1].y2)
		{
			samex=s[0].x1;
			samey=s[0].y1;
			fx=s[0].x2;fy=s[0].y2;
			sx=s[1].x1;sy=s[1].y1;
		}
		else if(s[0].x2==s[1].x1 && s[0].y2==s[1].y1)
		{
			samex=s[0].x2;
			samey=s[0].y2;
			fx=s[0].x1;fy=s[0].y1;
			sx=s[1].x2;sy=s[1].y2;
		}
		else if(s[0].x2==s[1].x2 && s[0].y2==s[1].y2)
		{
			samex=s[0].x2;
			samey=s[0].y2;
			fx=s[0].x1;fy=s[0].y1;
			sx=s[1].x1;sy=s[1].y1;
		}
		//cout<<fx<<" "<<fy<<" "<<sx<<" "<<sy<<" "<<samex<<" "<<samey;
		printf("%.3lf %.3lf\n",fx+sx-samex,fy+sy-samey);
	}
	return 0;
}
