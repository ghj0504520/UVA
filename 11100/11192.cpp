#include <iostream>

using namespace std;

void prin(string seq,int s,int d)
{
	for(int i=d;i>=s;i--)
		cout<<seq[i];
}
int main()
{
	int n;
	string seq;
	while(cin>>n,n)
	{
		cin>>seq;
		int mv,s,d,len=seq.size();
		mv=len/n;
		s=0,d=mv-1;
		s-=mv,d-=mv;
		while(d<len-1)
		{
			prin(seq,s+=mv,d+=mv);
		}
		cout<<'\n';
	}
	return 0;
}
