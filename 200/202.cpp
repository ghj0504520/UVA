#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	//freopen("out","w",stdout);
	int m,n;
	while(cin>>m>>n)
	{
		string point=" ";
		string tmp;
		int dec,r[10000]={0};
		dec=m/n;
		printf("%d/%d = %d.",m,n,dec);
		m%=n;
		r[m]=1;		
		m*=10;
		int pos;
		for(pos=2 ; ; pos++)
		{
			tmp=m/n+'0';
			point+=tmp;
			m%=n;
			if(r[m])break;
			r[m]=pos;
			m*=10;
		}
		int i,j,restart=r[m],reend=pos;
		for(i=1;i<=50;i++)
		{
			if(i==restart)
			{
				cout<<"(";
				break;
			}cout<<point[i];
		}
		for(j=i;j<reend && j<i+50;j++)
		{
			cout<<point[j];
		}
		if(reend>50)cout<<"...";
		cout<<")\n";
		cout<<"   "<<reend-restart<<" = number of digits in repeating cycle\n\n";
	}
	return 0;
}
