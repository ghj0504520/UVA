#include <iostream>

using namespace std;
int sum(int v)
{
	return v*(v+1)/2;
}

int main()
{
	int T;
	cin>>T;
	int sx,sy,dx,dy;
	for(int t=0 ; t<T ; t++)
	{
		cin>>sx>>sy>>dx>>dy;
		cout<<"Case "<<t+1<<": ";

		int sv=sx+sy,dv=dx+dy;
		sv=sum(sv)+(sv-sy);
		dv=sum(dv)+(dv-dy);

		cout<<dv-sv<<"\n";
	}
	return 0;
}