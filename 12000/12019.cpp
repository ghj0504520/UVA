#include <iostream>

using namespace std;

const char *day[7]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
int main()
{
	int num;
	cin>>num;
	int m,d;
	for(int i=0 ; i<num ; i++)
	{
		cin>>m>>d;
		int v=0;
		if(m==1)
			v=(d-10)%7;
		else if(m==2)
			v=(d-14)%7;
		else if(m==3)
			v=(d-14+28)%7;
		else if(m==4)
			v=(d-4)%7;
		else if(m==5)
			v=(d-9)%7;
		else if(m==6)
			v=(d-6)%7;
		else if(m==7)
			v=(d-11)%7;
		else if(m==8)
			v=(d-8)%7;
		else if(m==9)
			v=(d-5)%7;
		else if(m==10)
			v=(d-10)%7;
		else if(m==11)
			v=(d-7)%7;
		else if(m==12)
			v=(d-12)%7;
			
		v=(v+7)%7;
		cout<<day[v]<<'\n';
	}
}
