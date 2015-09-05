#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct rect
{
	double upLeftX,upLeftY,downRightX,downRightY;

	rect(double ulx,double uly,double drx,double dry)
	{
		upLeftX=ulx,upLeftY=uly,downRightX=drx,downRightY=dry;
	}
};
vector<rect> RECT;

bool checkIN(int idx,double X,double Y,int L)
{
	bool c=0;
	for(int i=0 ; i<L ; i++)
	{
		rect cur=RECT[i];
		if((X>cur.upLeftX && X<cur.downRightX)&&(Y<cur.upLeftY && Y>cur.downRightY))
		{
			c=1;
			cout<<"Point "<<idx<<" is contained in figure "<<i+1<<"\n";
		}
	}
	return c? 1 : 0;
}

int main()
{
	ios::sync_with_stdio(0);
	char n;
	int Len;
	while(cin>>n)
	{
		if(n=='*')break;
		double ulx,uly,drx,dry;
		cin>>ulx>>uly>>drx>>dry;
		RECT.push_back(rect(ulx,uly,drx,dry));
	}
	Len=RECT.size();
	double px,py;
	int num=0;
	while(cin>>px>>py)
	{
		if(px==9999.9 && py==9999.9)break;

		if(!checkIN(++num,px,py,Len))
			cout<<"Point "<<num<<" is not contained in any figure\n";

	}

	return 0;
}