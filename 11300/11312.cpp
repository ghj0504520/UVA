#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N,L,R,T;
int rI,lJ,rX,lY,gcd;

int EGCD(int a,int b)
{
	if(!b)
	{
		rI=1,lJ=0;
		return a;
	}
	else
	{
		int r=EGCD(b,a%b);
		int tmp=rI;
		rI=lJ;
		lJ=tmp-a/b*lJ;
		return r;
	}
}

bool checkBound(int x,int y,int cur)
{
	if(!x && !y) return 1;

	int k=min(x, (N-cur)/R);
	if(cur+R<=N && k)
		return checkBound(x-k,y,cur+R*k);
	k=min(y,cur/L);
	if(k) return checkBound(x,y-k,cur-L*k);
	
	return 0;
}

int main()
{
	int C;
	cin>>C;
	while(C--)
	{
		cin>>N>>L>>R>>T;
		N--;
		T--;

		//R*rX + L*lY = T
		//R*rI + L*lJ = gcd
		gcd=EGCD(R,L);
		if(T%gcd){cout<<"uh-oh!\n";continue;}
		int K=ceil(max(-1.0*rI*T/L,1.0*lJ*T/R));
		rX=(rI*T+L*K)/gcd;
		lY=(lJ*T-R*K)/gcd;


		if(checkBound(rX,-lY,0))
			cout<<rX-lY<<"\n";
		else
			cout<<"uh-oh!\n";
	}
	return 0;
}