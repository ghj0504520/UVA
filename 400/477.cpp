#include <iostream>
#include <vector>

using namespace std;

struct figure
{
	bool mode;

	double ulx,uly,lrx,lry;

	double cx,cy,cr;

	figure(string m)
	{
		if(m=="r")
			R();
		else 
			C();
	}

	void R()
	{
		mode=0;
		cin>>ulx>>uly>>lrx>>lry;
	}

	bool isR(double x,double y)
	{
		return x>ulx&&x<lrx&&y<uly&&y>lry;
	}

	void C()
	{
		mode=1;
		cin>>cx>>cy>>cr;
	}

	bool isC(double x,double y)
	{
		return (x-cx)*(x-cx)+(y-cy)*(y-cy)<cr*cr;
	}
};

int main()
{
	string in;
	vector<figure> data;
	while(cin>>in)
	{
		if(in=="*")break;

		data.push_back(figure(in));
	}
	int len=data.size(),T=0;
	double qx,qy;
	while(cin>>qx>>qy)
	{
		++T;
		if(qx==9999.9&&qy==9999.9)break;

		bool f=0;
		for(int i=0 ; i<len ; i++)
		{
			if(data[i].mode)
			{
				if(data[i].isC(qx,qy))
				{
					f=1;
					cout<<"Point "<<T<<" is contained in figure "<<i+1<<"\n";
				}
			}
			else
			{
				if(data[i].isR(qx,qy))
				{
					f=1;
					cout<<"Point "<<T<<" is contained in figure "<<i+1<<"\n";
				}
			}
		}

		if(!f)cout<<"Point "<<T<<" is not contained in any figure\n";

	}
	return 0;
}