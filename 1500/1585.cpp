#include <iostream>

using namespace std;

int main()
{
	int num;
	cin>>num;
	for(int i=0 ; i<num ; i++)
	{
		string seq;
		cin>>seq;
		int len=seq.length();
		
		int sum=0,cur=0;
		for(int i=0;i<len;i++)
		{
			if(seq[i]=='O')
			{
				cur++;
				sum+=cur;
			}
			else
			{
				cur=0;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
