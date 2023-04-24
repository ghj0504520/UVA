#include <iostream>
using namespace std;
 
int main() {
	int b, r, s;
	cin>>b;
	for(int t=1 ; t<=b ; t++)
	{
		cin>>r;
 
		int curSum=0,curI=-1,curJ=-1;
		int maxSum=0,maxI=-1,maxJ=-1;
		for(int it=0 ; it<r-1 ; it++)
		{
			cin>>s;
 
			curJ=it+1;
			if(curI==-1)curI=curJ;
 
			curSum+=s;
			if((curSum>maxSum) || (curSum==maxSum&& curJ-curI>maxJ-maxI))
			{
				maxSum = curSum;
				maxI=curI;
				maxJ=curJ;
			}
 
			if(curSum<0)
			{
				curSum = 0;
        		curI = -1;
			}
		}
 
		if (maxSum>0)
			cout<<"The nicest part of route "<<t<<" is between stops "<<maxI<<" and "<<maxJ+1<<"\n";
		else
			cout<<"Route "<<t<<" has no nice parts\n";
	}
	return 0;
}

