#include <iostream>

using namespace std;

int main()
{
	string in;
	while(cin>>in)
	{
		if(in=="*")break;

		int sum,correct=0;

		int len=in.size();
		for(int i=0 ; i<len ; i++)
		{
			switch(in[i])
			{
				case '/':
					if(sum==1000000)correct++;
					sum=0;
					break;
				case 'W'://1000000
					sum+=1000000;
					break;
				case 'H'://500000 2
					sum+=500000;
					break;
				case 'Q'://250000 4
					sum+=250000;
					break;
				case 'E'://125000 8	
					sum+=125000;
					break;
				case 'S'://62500 16
					sum+=62500;
					break;
				case 'T'://31250 32
					sum+=31250;
					break;
				case 'X'://15625 64
					sum+=15625;
					break;

			}
		}
		cout<<correct<<"\n";
	}
	return 0;
}