#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const double weight[4]={12.01,1.008,16.00,14.01};
int main()
{
	int num;
	cin>>num;
	for(int i=0 ; i<num ; i++)
	{
		char che[100];
		cin>>che;
		strcat(che,"*");
		int len=strlen(che);
		len--;
		int number=0;
		double sum=0.0;
		for(int i=0 ; i<len ; i++)
		{
			if(isalpha(che[i]))
			{
				number=0;
				if(!isdigit(che[i+1]))
				{
					number=1;
				}
				if(isdigit(che[i+1]) &&i+1<len)
				{
					
					number+=che[i+1]-'0';
					if(isdigit(che[i+2]) &&i+2<len)
					{
						number=number*10+(che[i+2]-'0');
					}
				}
				switch (che[i])
				{
					case 'C':
						sum+=weight[0]*number;
						break;
					case 'H':
						sum+=weight[1]*number;
						break;
					case 'O':
						sum+=weight[2]*number;
						break;
					case 'N':
						sum+=weight[3]*number;
						break;
				}
			}
		}printf("%.3lf\n",sum);
	}
	return 0;
}
