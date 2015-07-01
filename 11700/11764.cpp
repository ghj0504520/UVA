#include <iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int r=0;r<t;r++)
	{
		int num;
		cin>>num;
		int block[num];
		for(int i=0;i<num;i++)
			cin>>block[i];
		
		int h=0,l=0;
		for(int i=0;i<num-1;i++)
		{
			if(block[i]<block[i+1])
				h++;
			else if(block[i]>block[i+1])
				l++;
		}cout<<"Case "<<r+1<<": "<<h<<" "<<l<<"\n";
	}
	return 0;
}
