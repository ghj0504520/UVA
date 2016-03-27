#include <cstdio>
#include <iostream>
#include <cmath>

#define PI acos(-1.0)

using namespace std;

int main()
{
	double a,b,c;
	while(cin>>a)
	{
		cin>>b>>c;

		double s,v,r;

		double triangle=(a+b+c)/2.0;

		triangle=sqrt(triangle*(triangle-a)*(triangle-b)*(triangle-c));

		r=2*triangle/(a+b+c);
		r=r*r*PI;

		v=triangle-r;

		s=a*b*c/(4*triangle);
		s=s*s*PI;
		s-=triangle;

		printf("%.4lf %.4lf %.4lf\n",s,v,r);
	}
	return 0;
}