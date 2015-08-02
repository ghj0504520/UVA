#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	string in;
	while(getline(cin,in))
	{
		int M=0,tmp=0;
		int len=in.size();
		for(int i=0 ; i<len ;i++)
		{
			if(in[i]==' ')
			{
				tmp++;
			}
			else
			{
				if(tmp>M)
					M=tmp;
				tmp=0;
			}
		}
		double ans=log2(M);
		int ANS=ceil(ans);
		cout<<ANS<<"\n";
	}
	return 0;
}