#include <iostream>
using namespace std;

int main()
{
	int num,t=0;
	while(cin>>num)
	{
		t++;
		if(t>1)
			cout<<"\n";
		if(!num)
			break;
		
		int block[num],sum=0;
		for(int i=0;i<num;i++)
		{
			cin>>block[i];
			sum+=block[i];
		}
		sum/=num;
		int move=0;
		for(int i=0;i<num;i++)
		{
			if(block[i]>sum)
				move+=(block[i]-sum);
		}
		cout<<"Set #"<<t<<"\nThe minimum number of moves is "<<move<<".\n";
		
	}
	return 0;
}
