#include <iostream>
#include <cstdio>
using namespace std;

int getValue(int vx,int vy,int x,int y)
{
	return vy*x-vx*y;
}

int main()
{
	int T;
	cin>>T;
	int X[4],Y[4];
	cout<<"INTERSECTING LINES OUTPUT\n";
	for(int t=0 ; t<T ; t++)
	{
		for(int i=0 ; i<4 ; i++)
		{
			cin>>X[i]>>Y[i];
		}

		int vx1,vy1,vx2,vy2;
		vx1=X[1]-X[0];
		vy1=Y[1]-Y[0];
		vx2=X[3]-X[2];
		vy2=Y[3]-Y[2];

		if(vy1*vx2==vy2*vx1)
		{
			if(getValue(vx1,vy1,X[0],Y[0])==getValue(vx1,vy1,X[2],Y[2]))
			{
				cout<<"LINE\n";
			}
			else
			{
				cout<<"NONE\n";
			}
		}
		else
		{
			cout<<"POINT ";

			int v1=getValue(vx1,vy1,X[0],Y[0]),v2=getValue(vx2,vy2,X[2],Y[2]);

			double det=(-1*vy1*vx2)-(-1*vy2*vx1);

			double detX=vx1*v2-vx2*v1,detY=-1*(-1*vy1*v2+vy2*v1);

			printf("%.2lf %.2lf\n",(double)detX/det,(double)detY/det);
		}
	}
	cout<<"END OF OUTPUT\n";
	return 0;
}