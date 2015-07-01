#include <iostream>
#include <algorithm>
using namespace std;
struct dice
{
	int f,b;
};
bool cmp(const dice &i,const dice &j)
{
	return i.f<j.f || (i.f==j.f && i.b<j.b);
}


void DICE_sort(dice p[])
{
	for(int i=0;i<3;i++)
		if(p[i].f>p[i].b)
		{
			int swap=p[i].f;
			p[i].f=p[i].b;
			p[i].b=swap;
		}
	
	sort(p,p+3,cmp);
	
}

bool DICE(int d1[],int d2[])
{
	dice pair1[3],pair2[3];
	
	pair1[0].f=d1[0];
	pair1[0].b=d1[5];
	pair1[1].f=d1[1];
	pair1[1].b=d1[4];
	pair1[2].f=d1[2];
	pair1[2].b=d1[3];
	
	pair2[0].f=d2[0];
	pair2[0].b=d2[5];
	pair2[1].f=d2[1];
	pair2[1].b=d2[4];
	pair2[2].f=d2[2];
	pair2[2].b=d2[3];
	
	DICE_sort(pair1);
	DICE_sort(pair2);
	for(int i=0;i<3;i++)
	{
		if(pair1[i].f!=pair2[i].f || pair1[i].b!=pair2[i].b)
			return 0;
	}
	return 1;
}
int main()
{
	string d;
	while(cin>>d)
	{
		int d1[6],d2[56];
		for(int i=0;i<6;i++)
			d1[i]=d[i];
		for(int i=0;i<6;i++)
			d2[i]=d[i+6];
		
		!DICE(d1,d2)?cout<<"FALSE\n":cout<<"TRUE\n";
	}
	return 0;
}
