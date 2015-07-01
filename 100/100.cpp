#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

long long int threeN(long long int k)
{
  long long int sum=1;
	while(k!=1)
	{
		if(k%2==1)
			k=k*3+1;
		else 
			k/=2;
	
		sum++;
	}return sum;
}
int main()
{
  
	long long int a[2];
	while(cin>>a[0]>>a[1]){
	long long int b[2];
	b[0]=a[0];
	b[1]=a[1];
 	sort(b,b+2);
 	long long int max=0;
 	for(long long int i=b[0];i<=b[1];i++)
 	{
		long long int p;
		p=threeN(i);
		if(p>max)
		max=p;
			
	}cout<<a[0]<<' '<<a[1]<<' '<<max<<'\n';
}
}
