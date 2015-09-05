#include <iostream>

using namespace std;

bool check;
int balanceJudge()
{
	int W1,D1,W2,D2;
	cin>>W1>>D1>>W2>>D2;
	if(!W1)	W1=balanceJudge();
	if(!W2)	W2=balanceJudge();
	if(W1*D1!=W2*D2)check=0;
	return W1+W2;
}

int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		check=1;
		balanceJudge();
		check?cout<<"YES" : cout<<"NO" ;
		cout<<"\n";
		if(t)cout<<"\n";
	}
	return 0;
}